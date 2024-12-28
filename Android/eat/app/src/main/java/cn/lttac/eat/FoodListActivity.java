package cn.lttac.eat;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import androidx.appcompat.app.AppCompatActivity;
import android.content.SharedPreferences;
import android.widget.TextView;

public class FoodListActivity extends AppCompatActivity {
    private SharedPreferences sharedPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        String savedUsername = sharedPreferences.getString("username", "");
        String savedPassword = sharedPreferences.getString("password", "");
        setContentView(R.layout.activity_food_list);
        TextView infoText = findViewById(R.id.infoText);
        infoText.setText("欢迎" + savedUsername  + "! 学号"+savedPassword);
        // 食物名称数组
        final String[] foodNames = {
                "牛排", "附魔金苹果", "谜之炖菜", "牛奶", "蜂蜜瓶", "蜘蛛眼"
        };

        // 控件ID数组
        final int[] buttonIds = {
                R.id.foodImage1,
                R.id.foodImage2,
                R.id.foodImage3,
                R.id.foodImage4,
                R.id.foodImage5,
                R.id.foodImage6
        };

        // 遍历每个ImageView并为其设置点击事件
        for (int i = 0; i < buttonIds.length; i++) {
            // 获取ImageView控件
            ImageView foodImageView = findViewById(buttonIds[i]);
            // 为每个ImageView设置点击事件监听器
            int finalI = i;
            foodImageView.setOnClickListener(v -> {
                // 获取点击的食物名称
                String foodName = foodNames[finalI];
                // 跳转到详情页并传递食物名称
                openDetail(foodName);
            });
        }
    }

    private void openDetail(String foodName) {
        // 创建Intent并传递食物名称
        Intent intent = new Intent(FoodListActivity.this, FoodDetailActivity.class);
        intent.putExtra("foodName", foodName);  // 传递食物名称
        startActivity(intent);  // 启动详情页
    }
}
