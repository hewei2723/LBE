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
            String username = usernameEditText.getText().toString();
            String password = passwordEditText.getText().toString();
            if (username.equals("何炜") && password.equals("2022010611")) {
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
    }
    private void initializeDatabase() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT COUNT(*) FROM " + sqlite.TABLE_FOOD, null);
        cursor.moveToFirst();
        int count = cursor.getInt(0);
        cursor.close();
        if (count == 0) {
            dbHelper.insertFoodData(db);
        }
    }
}
