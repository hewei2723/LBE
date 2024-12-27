package cn.lttac.eat;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import androidx.appcompat.app.AppCompatActivity;
public class FoodListActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_food_list);

        // 食物名称数组
        final String[] foodNames = {
                "牛排", "附魔金苹果", "坏炖菜", "牛奶", "蜂蜜瓶", "蜘蛛眼"
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
