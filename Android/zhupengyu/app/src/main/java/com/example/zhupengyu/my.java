package com.example.zhupengyu;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
public class my extends AppCompatActivity {
    private TextView tvUserInfo;
    private Button btnLogout, btnHome, btnMy;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my);
        tvUserInfo = findViewById(R.id.uinfo);
        btnLogout = findViewById(R.id.logoutButton);
        btnHome = findViewById(R.id.homeButton);
        btnMy = findViewById(R.id.myButton);
        // 获取传递过来的用户名并显示
        String userName = getSharedPreferences("loginPrefs", MODE_PRIVATE).getString("username", "");
        tvUserInfo.setText("当前用户: " + userName);
        btnLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                logout();
            }
        });
        btnHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(my.this, NewsActivity.class));
            }
        });
        btnMy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(my.this, my.class));
            }
        });
        btnHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(my.this, NewsActivity.class));
            }
        });
        btnMy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(my.this, my.class));
            }
        });
    }

    private void logout() {
        SharedPreferences prefs = getSharedPreferences("loginPrefs", MODE_PRIVATE);
        String userName = prefs.getString("username", "");
        String pwd = prefs.getString("password", "");
        SharedPreferences.Editor editor = prefs.edit();
        editor.putString("username", userName);
        editor.putString("password", pwd);
        editor.apply();
        Toast.makeText(this, "已退出登录", Toast.LENGTH_SHORT).show();
        startActivity(new Intent(my.this, LoginActivity.class));
        finish();
    }
}
