package cn.lttac.eat;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {

    private EditText usernameEditText;
    private EditText passwordEditText;
    private CheckBox rememberMeCheckBox;
    private SharedPreferences sharedPreferences;
    private SQLiteHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        // 初始化控件
        usernameEditText = findViewById(R.id.username);
        passwordEditText = findViewById(R.id.password);
        rememberMeCheckBox = findViewById(R.id.remember);
        sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        // 初始化数据库助手
        dbHelper = new SQLiteHelper(this);
        // 初始化数据，如果数据库为空，则插入默认食物数据
        initializeDatabase();
        // 获取保存的用户名和密码（如果记住密码被选中）
        String savedUsername = sharedPreferences.getString("username", "");
        String savedPassword = sharedPreferences.getString("password", "");
        boolean rememberMe = sharedPreferences.getBoolean("rememberMe", false);
        // 如果记住密码，自动填充用户名和密码
        if (rememberMe) {
            usernameEditText.setText(savedUsername);
            passwordEditText.setText(savedPassword);
            rememberMeCheckBox.setChecked(true);
        }
        // 登录按钮点击事件
        findViewById(R.id.loginButton).setOnClickListener(v -> {
            String username = usernameEditText.getText().toString();
            String password = passwordEditText.getText().toString();

            if (username.equals("何炜") && password.equals("2022010611")) {
                // 保存用户名、密码和是否记住密码的状态
                SharedPreferences.Editor editor = sharedPreferences.edit();
                if (rememberMeCheckBox.isChecked()) {
                    editor.putString("username", username);
                    editor.putString("password", password);
                    editor.putBoolean("rememberMe", true);
                } else {
                    editor.clear();
                }
                editor.apply();

                // 登录成功，跳转到 FoodListActivity
                Intent intent = new Intent(LoginActivity.this, FoodListActivity.class);
                intent.putExtra("username", username);
                startActivity(intent);
                finish();
            } else {
                // 登录失败
                Toast.makeText(LoginActivity.this, "登录失败", Toast.LENGTH_SHORT).show();
            }
        });
    }
    // 初始化数据库数据（如果数据库为空，插入默认数据）
    private void initializeDatabase() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        // 检查数据库是否已经包含默认数据（通过检查食物表中的记录数）
        Cursor cursor = db.rawQuery("SELECT COUNT(*) FROM " + SQLiteHelper.TABLE_FOOD, null);
        cursor.moveToFirst();
        int count = cursor.getInt(0);
        cursor.close();
        // 如果表中没有数据，则插入默认数据
        if (count == 0) {
            dbHelper.insertFoodData(db);
        }
    }
}
