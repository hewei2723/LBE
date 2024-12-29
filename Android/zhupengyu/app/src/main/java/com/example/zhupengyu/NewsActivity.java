package com.example.zhupengyu;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import androidx.appcompat.app.AppCompatActivity;

public class NewsActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_news);
        LinearLayout llNvda = findViewById(R.id.nvda);
        LinearLayout llXiaomi = findViewById(R.id.xiaomi);
        LinearLayout llTlsy = findViewById(R.id.tlsy);
        LinearLayout llQualcomm = findViewById(R.id.qualcomm);
        Button btnHome = findViewById(R.id.homeButton);
        Button btnMy = findViewById(R.id.myButton);
        llNvda.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openDetailActivity(1);
            }
        });
        llXiaomi.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openDetailActivity(2);
            }
        });
        llTlsy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openDetailActivity(3);
            }
        });
        llQualcomm.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openDetailActivity(4);
            }
        });
        btnHome.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(NewsActivity.this, NewsActivity.class));
            }
        });
        btnMy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(NewsActivity.this, my.class));
            }
        });
    }
    private void openDetailActivity(int articleId) {
        Intent intent = new Intent(NewsActivity.this, newsinfo.class);
        intent.putExtra("ARTICLE_ID", articleId);
        startActivity(intent);
    }
}
