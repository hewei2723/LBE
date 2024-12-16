package cn.lttac.todaynews;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class UnLogin extends Fragment {

    private EditText editUsername, editPassword;
    private Button btnLogin, btnRegister;
    private SqlDB dbHelper;
    private SharedPreferences preferences;

    public UnLogin() {
        // Required empty public constructor
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.unlogin,container, false);

        dbHelper = new SqlDB(getContext());
        preferences = requireActivity().getSharedPreferences("login_prefs", getContext().MODE_PRIVATE);

        editUsername = view.findViewById(R.id.editText_username);
        editPassword = view.findViewById(R.id.editText_password);
        btnLogin = view.findViewById(R.id.button_login);
        btnRegister = view.findViewById(R.id.button_register);

        // 自动登录
        if (preferences.getBoolean("isLoggedIn", false)) {
            startHomeActivity(preferences.getString("username", ""));
        }

        btnRegister.setOnClickListener(v -> {
            String username = editUsername.getText().toString();
            String password = editPassword.getText().toString();

            if (dbHelper.registerUser(username, password)) {
                Toast.makeText(getContext(), "注册成功", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(getContext(), "注册失败", Toast.LENGTH_SHORT).show();
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

        return view;
    }

    private void startHomeActivity(String username) {
        // 创建 Fragment 并传递数据
        Login myFragment = new Login();
        Bundle args = new Bundle();
        args.putString("username", username);
        myFragment.setArguments(args);
        // 替换当前 Fragment 或加载到容器中
        requireActivity().getSupportFragmentManager().beginTransaction()
                .replace(R.id.fragment_container, myFragment)
                .addToBackStack(null)
                .commit();
    }

}
