package com.example.tour;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
public class go extends AppCompatActivity {
    private EditText usernameEditText, passwordEditText;
    private CheckBox rememberPasswordCheckBox;
    private SharedPreferences sharedPreferences;
    private static final String PREFS_NAME = "LoginPrefs";
    private static final String KEY_USERNAME = "username";
    private static final String KEY_PASSWORD = "password";
    private static final String KEY_Dont_forget_me = "Dont_forget_me";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        initData();
        usernameEditText = findViewById(R.id.username);
        passwordEditText = findViewById(R.id.password);
        rememberPasswordCheckBox = findViewById(R.id.remember_password);
        Button loginButton = findViewById(R.id.login_button);
        sharedPreferences = getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE);
        String savedUsername = sharedPreferences.getString(KEY_USERNAME, "");
        String savedPassword = sharedPreferences.getString(KEY_PASSWORD, "");
        boolean rememberMe = sharedPreferences.getBoolean(KEY_Dont_forget_me, false);
        if (rememberMe) {
            usernameEditText.setText(savedUsername);
            passwordEditText.setText(savedPassword);
            rememberPasswordCheckBox.setChecked(true);
        }
        String uname = "余孟莹";
        String mysecret = "2022010428";
        loginButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String username = usernameEditText.getText().toString();
                String password = passwordEditText.getText().toString();
                boolean rememberMe = rememberPasswordCheckBox.isChecked();
                SharedPreferences.Editor editor = sharedPreferences.edit();
                if (rememberMe) {
                    editor.putString(KEY_USERNAME, username);
                    editor.putString(KEY_PASSWORD, password);
                } else {
                    editor.remove(KEY_USERNAME);
                    editor.remove(KEY_PASSWORD);
                }
                editor.putBoolean(KEY_Dont_forget_me, rememberMe);
                editor.apply();
                if (username.equals(uname) && password.equals(mysecret)) {

                    Intent intent = new Intent(go.this, show.class);
                    intent.putExtra("username", username);
                    intent.putExtra("password", password);
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(go.this, "用户名或密码错误", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
    private void initData() {
        db dbHelper = new db(this);
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        Cursor cursor = db.rawQuery("SELECT COUNT(*) FROM " + com.example.tour.db.TABLE_NAME, null);
        cursor.moveToFirst();
        int count = cursor.getInt(0);
        cursor.close();
        if (count == 0) {
            db.execSQL("INSERT INTO " + com.example.tour.db.TABLE_NAME + " (" +
                            com.example.tour.db.COLUMN_NAME + ", " +
                            com.example.tour.db.COLUMN_DESCRIPTION + ", " +
                            com.example.tour.db.COLUMN_IMAGE + ") VALUES (?, ?, ?)",
                    new Object[]{"龙门石窟", "龙门石窟位于河南洛阳，是中国四大石窟之一，拥有超过2300个石窟和100,000余尊佛像。石窟雕刻艺术精湛，展现了中国古代佛教文化的辉煌，是世界文化遗产。", "t1"});
            db.execSQL("INSERT INTO " + com.example.tour.db.TABLE_NAME + " (" +
                            com.example.tour.db.COLUMN_NAME + ", " +
                            com.example.tour.db.COLUMN_DESCRIPTION + ", " +
                            com.example.tour.db.COLUMN_IMAGE + ") VALUES (?, ?, ?)",
                    new Object[]{"布达拉宫", "布达拉宫位于西藏拉萨，是藏传佛教的圣地，也是历代达赖喇嘛的冬宫。宫内藏有丰富的历史遗物、艺术品与宗教文物，是世界上最高的宫殿之一，享有“世界屋脊的明珠”之称。", "t2"});

            db.execSQL("INSERT INTO " + com.example.tour.db.TABLE_NAME + " (" +
                            com.example.tour.db.COLUMN_NAME + ", " +
                            com.example.tour.db.COLUMN_DESCRIPTION + ", " +
                            com.example.tour.db.COLUMN_IMAGE + ") VALUES (?, ?, ?)",
                    new Object[]{"桂林山水", "桂林位于广西，是中国最著名的风景区之一，以奇峰异石和秀丽的漓江而闻名。独特的喀斯特地貌造就了如画的山水风光，是游客和摄影师的天堂。", "t3"});
            db.execSQL("INSERT INTO " + com.example.tour.db.TABLE_NAME + " (" +
                            com.example.tour.db.COLUMN_NAME + ", " +
                            com.example.tour.db.COLUMN_DESCRIPTION + ", " +
                            com.example.tour.db.COLUMN_IMAGE + ") VALUES (?, ?, ?)",
                    new Object[]{"丽江古城", "丽江古城位于云南，是中国保存最完好的古代城市之一，具有浓厚的纳西族文化特色。古城内街巷曲折，建筑风格独特，深受游客青睐，是世界文化遗产。", "t4"});
        }
        db.close();
    }

}

