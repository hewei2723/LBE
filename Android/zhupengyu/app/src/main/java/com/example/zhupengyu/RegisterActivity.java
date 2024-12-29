package com.example.zhupengyu;

import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class RegisterActivity extends AppCompatActivity {
    private EditText etUser, etPwd, etConfPwd;
    private SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reg);
        makedb dbHelper = new makedb(this);
        db = dbHelper.getWritableDatabase();
        etUser = findViewById(R.id.usename);
        etPwd = findViewById(R.id.usepwd);
        etConfPwd = findViewById(R.id.usepwd2);
        Button btnSubmit = findViewById(R.id.submit);
        btnSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                registerUser();
            }
        });
    }
    private void registerUser() {
        String username = etUser.getText().toString();
        String password = etPwd.getText().toString();
        String confirmPassword = etConfPwd.getText().toString();

        if (password.equals(confirmPassword)) {
            ContentValues values = new ContentValues();
            values.put("username", username);
            values.put("password", password);
            long newRowId = db.insert("users", null, values);
            if (newRowId != -1) {
                Toast.makeText(this, "注册成功", Toast.LENGTH_SHORT).show();
                finish();
            } else {
                Toast.makeText(this, "注册失败", Toast.LENGTH_SHORT).show();
            }
        } else {
            Toast.makeText(this, "密码不一致", Toast.LENGTH_SHORT).show();
        }
    }
}
