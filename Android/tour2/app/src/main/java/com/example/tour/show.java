package com.example.tour;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
public class show extends AppCompatActivity {
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ImageView imageView1 = findViewById(R.id.imageView1);
        ImageView imageView2 = findViewById(R.id.imageView2);
        ImageView imageView3 = findViewById(R.id.imageView3);
        ImageView imageView4 = findViewById(R.id.imageView4);
        TextView usernameTextView = findViewById(R.id.textView);
        Intent intent = getIntent();
        String username = intent.getStringExtra("username");
        String password = intent.getStringExtra("password");
        usernameTextView.setText("欢迎，" + username + password);
        imageView1.setOnClickListener(view -> opensays("龙门石窟"));
        imageView2.setOnClickListener(view -> opensays("布达拉宫"));
        imageView3.setOnClickListener(view -> opensays("桂林山水"));
        imageView4.setOnClickListener(view -> opensays("丽江古城"));
    }
    private void opensays(String sceneName) {
        Intent intent = new Intent(show.this, says.class);
        intent.putExtra("scene_name", sceneName);
        startActivity(intent);
    }
}
