package com.example.zhupengyu;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
public class LoginActivity extends AppCompatActivity {
    private EditText etName, etPwd;
    private CheckBox cbRemember;
    private SQLiteDatabase db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        makedb dbHelper = new makedb(this);
        db = dbHelper.getWritableDatabase();
        etName = findViewById(R.id.name);
        etPwd = findViewById(R.id.pwd);
        cbRemember = findViewById(R.id.remember);
        Button btnLogin = findViewById(R.id.login);
        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                performLogin();
            }
        });
        Button btnReg = findViewById(R.id.reg);
        btnReg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(LoginActivity.this, RegisterActivity.class));
            }
        });
        // 自动填充用户名和密码
        autoFill();
    }
    private void performLogin() {
        String username = etName.getText().toString();
        String password = etPwd.getText().toString();
        Cursor cursor = db.rawQuery("SELECT * FROM users WHERE username=? AND password=?", new String[]{username, password});
        if (cursor != null && cursor.moveToFirst()) {
            if (cbRemember.isChecked()) {
                saveLogin(username, password);
            }
            Toast.makeText(this, "登录成功", Toast.LENGTH_SHORT).show();
            cursor.close();
            Intent intent = new Intent(LoginActivity.this, NewsActivity.class);
            intent.putExtra("username", username);
            startActivity(intent);
            finish();
        } else {
            Toast.makeText(this, "用户名或密码错误", Toast.LENGTH_SHORT).show();
        }
    }

    private void saveLogin(String username, String password) {
        getSharedPreferences("loginPrefs", MODE_PRIVATE)
                .edit()
                .putString("username", username)
                .putString("password", password)
                .apply();
    }

    private void autoFill() {
        String username = getSharedPreferences("loginPrefs", MODE_PRIVATE).getString("username", "");
        String password = getSharedPreferences("loginPrefs", MODE_PRIVATE).getString("password", "");
        etName.setText(username);
        etPwd.setText(password);
        cbRemember.setChecked(!username.isEmpty() && !password.isEmpty());
    }
}
