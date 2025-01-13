package cn.lttac.todaynews;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import android.os.Handler;
import android.os.Looper;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Objects;

public class UnLogin extends Fragment {
    private EditText editUsername, editPassword;
    public TextView yiyan;
    private SqlDB dbHelper;
    private SharedPreferences preferences;
    private Handler handler = new Handler(Looper.getMainLooper());
    private Runnable updateRunnable;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.unlogin, container, false);
        dbHelper = new SqlDB(getContext());
        preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);
        editUsername = view.findViewById(R.id.editText_username);
        editPassword = view.findViewById(R.id.editText_password);
        yiyan = view.findViewById(R.id.textView3);
        Button btnLogin = view.findViewById(R.id.button_login);
        Button btnRegister = view.findViewById(R.id.button_register);

        if (preferences.getBoolean("isLoggedIn", false)) {
            startHomeActivity(preferences.getString("username", ""));
        }

        btnRegister.setOnClickListener(v -> {
            String username = editUsername.getText().toString().trim();
            String password = editPassword.getText().toString().trim();
            if (username.isEmpty() || password.isEmpty()) {
                Toast.makeText(getContext(), "用户名和密码不能为空", Toast.LENGTH_SHORT).show();
            } else {
                if (dbHelper.registerUser(username, password)) {
                    Toast.makeText(getContext(), "注册成功", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(getContext(), "注册失败", Toast.LENGTH_SHORT).show();
                }
            }
        });

        btnLogin.setOnClickListener(v -> {
            String username = editUsername.getText().toString();
            String password = editPassword.getText().toString();
            if (dbHelper.loginUser(username, password)) {
                preferences.edit().putBoolean("isLoggedIn", true).putString("username", username).apply();
                startHomeActivity(username);
            } else {
                Toast.makeText(getContext(), "登录失败，请检查账号和密码", Toast.LENGTH_SHORT).show();
            }
        });

        // 初始化 Runnable，用于每秒更新一次数据
        updateRunnable = new Runnable() {
            @Override
            public void run() {
                fetchYiyanData();
                handler.postDelayed(this, 3000); // 每秒执行一次
            }
        };
        handler.post(updateRunnable); // 开始执行 Runnable

        return view;
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        handler.removeCallbacks(updateRunnable); // 停止更新
    }

    private void fetchYiyanData() {
        new Thread(() -> {
            try {
                URL url = new URL("https://news.api.lttac.cn/yiyan");
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("GET");
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder result = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    result.append(line);
                }
                reader.close();
                String yiyanText = result.toString();
                requireActivity().runOnUiThread(() -> yiyan.setText(yiyanText));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }).start();
    }
    private void startHomeActivity(String username) {
        Login myFragment = new Login();
        Bundle args = new Bundle();
        args.putString("username", username);
        myFragment.setArguments(args);
        requireActivity().getSupportFragmentManager().beginTransaction()
                .replace(R.id.fragment_container, myFragment)
                .addToBackStack(null)
                .commit();
    }
}
