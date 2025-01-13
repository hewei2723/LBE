package cn.lttac.eat;

import android.content.ContentValues;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class login extends AppCompatActivity {
    private EditText usernameEditText;
    private EditText passwordEditText;
    private CheckBox rememberMeCheckBox;
    private SharedPreferences sharedPreferences;
    private sqlite dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        usernameEditText = findViewById(R.id.username);
        passwordEditText = findViewById(R.id.password);
        rememberMeCheckBox = findViewById(R.id.remember);
        sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        dbHelper = new sqlite(this);
        initializeDatabase();

        String savedUsername = sharedPreferences.getString("username", "");
        String savedPassword = sharedPreferences.getString("password", "");
        boolean rememberMe = sharedPreferences.getBoolean("rememberMe", false);

        if (rememberMe) {
            usernameEditText.setText(savedUsername);
            passwordEditText.setText(savedPassword);
            rememberMeCheckBox.setChecked(true);
        }

        findViewById(R.id.loginButton).setOnClickListener(v -> {
            String username = usernameEditText.getText().toString().trim();
            String password = passwordEditText.getText().toString().trim();

            if (isValidUser(username, password)) {
                SharedPreferences.Editor editor = sharedPreferences.edit();
                if (rememberMeCheckBox.isChecked()) {
                    editor.putString("username", username);
                    editor.putString("password", password);
                    editor.putBoolean("rememberMe", true);
                } else {
                    editor.clear();
                }
                editor.apply();
                Intent intent = new Intent(login.this, list.class);
                intent.putExtra("username", username);
                startActivity(intent);
                finish();
            } else {
                Toast.makeText(login.this, "登录失败", Toast.LENGTH_SHORT).show();
            }
        });

        findViewById(R.id.regButton).setOnClickListener(v -> {
            String username = usernameEditText.getText().toString().trim();
            String password = passwordEditText.getText().toString().trim();

            if (username.isEmpty() || password.isEmpty()) {
                Toast.makeText(login.this, "用户名和密码不能为空", Toast.LENGTH_SHORT).show();
                return;
            }

            if (registerUser(username, password)) {
                Toast.makeText(login.this, "注册成功", Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(login.this, "注册失败，用户名可能已存在", Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void initializeDatabase() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT COUNT(*) FROM " + sqlite.TABLE_FOOD, null);
        cursor.moveToFirst();
        int count = cursor.getInt(0);
        cursor.close();
        if (count == 0) {
            dbHelper.insertFoodData(db);
            dbHelper.insertDefaultUser(db);
        }
    }

    private boolean isValidUser(String username, String password) {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + sqlite.TABLE_USERS + " WHERE " + sqlite.COLUMN_USERNAME + " = ? AND " + sqlite.COLUMN_PASSWORD + " = ?", new String[]{username, password});
        boolean exists = cursor.getCount() > 0;
        cursor.close();
        return exists;
    }
    private boolean registerUser(String username, String password) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + sqlite.TABLE_USERS + " WHERE " + sqlite.COLUMN_USERNAME + " = ?", new String[]{username});
        if (cursor.getCount() > 0) {
            cursor.close();
            return false;
        } else {
            cursor.close();
            ContentValues values = new ContentValues();
            values.put(sqlite.COLUMN_USERNAME, username);
            values.put(sqlite.COLUMN_PASSWORD, password);
            db.insert(sqlite.TABLE_USERS, null, values);
            return true;
        }
    }
}
