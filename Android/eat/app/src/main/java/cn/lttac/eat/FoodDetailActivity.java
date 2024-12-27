package cn.lttac.eat;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
public class FoodDetailActivity extends AppCompatActivity {
    private SQLiteHelper dbHelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_food_detail);

        // 初始化数据库助手
        dbHelper = new SQLiteHelper(this);

        // 获取传递的食物名称
        String foodName = getIntent().getStringExtra("foodName");

        // 获取ImageView和TextView控件
        ImageView foodImageView = findViewById(R.id.foodImage);
        TextView foodDescriptionTextView = findViewById(R.id.foodDescription);

        // 根据食物名称设置对应的图片和描述
        if (foodName != null) {
            int imageRes = getImageResource(foodName);  // 获取对应的图片资源
            String description = dbHelper.getFoodDescription(foodName);  // 从数据库获取描述

            // 设置图片和描述
            foodImageView.setImageResource(imageRes);
            foodDescriptionTextView.setText(description);
        }
    }
    // 根据食物名称返回图片资源ID
    private int getImageResource(String foodName) {
        switch (foodName) {
            case "牛排":
                return R.drawable.food1;
            case "附魔金苹果":
                return R.drawable.food2;
            case "坏炖菜":
                return R.drawable.food3;
            case "牛奶":
                return R.drawable.food4;
            case "蜂蜜瓶":
                return R.drawable.food5;
            case "蜘蛛眼":
                return R.drawable.food6;
            default:
                return R.drawable.food1;  // 默认图片
        }
    }
}
