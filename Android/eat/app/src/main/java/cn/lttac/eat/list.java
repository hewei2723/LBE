package cn.lttac.eat;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class list extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        SharedPreferences sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        String savedUsername = sharedPreferences.getString("username", "");
        String savedPassword = sharedPreferences.getString("password", "");
        setContentView(R.layout.activity_food_list);

        TextView infoText = findViewById(R.id.infoText);
        infoText.setText("欢迎" + savedUsername + "! 学号" + savedPassword);

        // 设置退出登录按钮的点击事件
        Button logoutButton = findViewById(R.id.logoutButton);
        logoutButton.setOnClickListener(v -> {
            Intent intent = new Intent(list.this, login.class);
            startActivity(intent);
            finish();
        });

        final String[] foodNames = {
                "牛排", "附魔金苹果", "谜之炖菜", "牛奶", "蜂蜜瓶", "蜘蛛眼"
        };
        final int[] buttonIds = {
                R.id.foodImage1,
                R.id.foodImage2,
                R.id.foodImage3,
                R.id.foodImage4,
                R.id.foodImage5,
                R.id.foodImage6
        };

        for (int i = 0; i < buttonIds.length; i++) {
            ImageView foodImageView = findViewById(buttonIds[i]);
            int finalI = i;
            foodImageView.setOnClickListener(v -> {
                String foodName = foodNames[finalI];
                openDetail(foodName);
            });
        }
    }

    private void openDetail(String foodName) {
        Intent intent = new Intent(list.this, info.class);
        intent.putExtra("foodName", foodName);
        startActivity(intent);
    }
}
