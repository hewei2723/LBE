package cn.lttac.todaynews;
import android.content.Context;
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
    private SqlDB dbHelper;
    private SharedPreferences preferences;
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.unlogin,container, false);
        dbHelper = new SqlDB(getContext());
        getContext();
        preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);
        editUsername = view.findViewById(R.id.editText_username);
        editPassword = view.findViewById(R.id.editText_password);
        Button btnLogin = view.findViewById(R.id.button_login);
        Button btnRegister = view.findViewById(R.id.button_register);
        // 自动登录
        // 检查用户是否已经登录
        if (preferences.getBoolean("isLoggedIn", false)) {
            // 如果已经登录，则跳转到主界面
            startHomeActivity(preferences.getString("username", ""));
        }
        // 设置注册按钮的点击事件
        btnRegister.setOnClickListener(v -> {
            // 获取用户输入的用户名和密码
            String username = editUsername.getText().toString();
            String password = editPassword.getText().toString();

            // 调用数据库帮助类的方法注册用户
            if (dbHelper.registerUser(username, password)) {
                // 如果注册成功，则显示注册成功的提示信息
                Toast.makeText(getContext(), "注册成功", Toast.LENGTH_SHORT).show();
            } else {
                // 如果注册失败，则显示注册失败的提示信息
                Toast.makeText(getContext(), "注册失败", Toast.LENGTH_SHORT).show();
            }
        });

        // 设置登录按钮的点击事件
        btnLogin.setOnClickListener(v -> {
            // 获取用户名和密码
            String username = editUsername.getText().toString();
            String password = editPassword.getText().toString();

            // 调用数据库帮助类的方法，判断用户名和密码是否正确
            if (dbHelper.loginUser(username, password)) {
                // 如果正确，将登录状态和用户名保存到SharedPreferences中
                preferences.edit().putBoolean("isLoggedIn", true).putString("username", username).apply();
                // 跳转到主界面
                startHomeActivity(username);
            } else {
                // 如果不正确，弹出提示框
                Toast.makeText(getContext(), "登录失败，请检查账号和密码", Toast.LENGTH_SHORT).show();
            }
        });

        return view;
    }

    private void startHomeActivity(String username) {
        // 创建 Fragment 并传递数据
        // 创建一个Login对象
        Login myFragment = new Login();
        // 创建一个Bundle对象
        Bundle args = new Bundle();
        // 将username字符串放入Bundle中
        args.putString("username", username);
        // 将Bundle对象设置给Login对象
        myFragment.setArguments(args);
        // 替换当前 Fragment 或加载到容器中
        // 获取当前Activity的FragmentManager
        requireActivity().getSupportFragmentManager().beginTransaction()
                // 替换fragment_container中的fragment为myFragment
                .replace(R.id.fragment_container, myFragment)
                // 将当前fragment添加到回退栈中
                .addToBackStack(null)
                // 提交事务
                .commit();
    }

}
