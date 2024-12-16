package cn.lttac.news;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class Login extends AppCompatActivity {

    private EditText etUsername, etPassword;
    private Button btnLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);  // 设置 Activity 布局

        // 绑定控件
        etUsername = findViewById(R.id.etUsername);
        etPassword = findViewById(R.id.etPassword);
        btnLogin = findViewById(R.id.btnLogin);

        // 登录按钮点击事件
        btnLogin.setOnClickListener(v -> {
            String username = etUsername.getText().toString().trim();
            String password = etPassword.getText().toString().trim();

            if ("1".equals(username) && "1".equals(password)) {
                Toast.makeText(Login.this, "登录成功", Toast.LENGTH_SHORT).show();
                // 跳转到成功页面
                Intent intent = new Intent(this, Success.class);
                startActivity(intent);
                finish(); // 关闭当前页面，防止返回到登录页
            } else {
                Toast.makeText(Login.this, "用户名或密码错误", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
