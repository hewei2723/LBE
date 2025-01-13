package cn.lttac.eat;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
public class info extends AppCompatActivity {
    private sqlite dbHelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_food_detail);
        dbHelper = new sqlite(this);
        String foodName = getIntent().getStringExtra("foodName");
        ImageView foodImageView = findViewById(R.id.foodImage);
        TextView foodDescriptionTextView = findViewById(R.id.foodDescription);
        if (foodName != null) {
            int imageRes = getImageResource(foodName);
            String description = dbHelper.getFoodDescription(foodName);
            foodImageView.setImageResource(imageRes);
            foodDescriptionTextView.setText(description);
        }
    }
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
                return R.drawable.food1;
        }
    }
}
