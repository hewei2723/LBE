package com.example.zhupengyu;

import android.annotation.SuppressLint;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class newsinfo extends AppCompatActivity {

    private TextView tvTitle, tvContent;
    private SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_newinfo);

        tvTitle = findViewById(R.id.title);
        tvContent = findViewById(R.id.content);

        makedb dbHelper = new makedb(this);
        db = dbHelper.getWritableDatabase();

        int articleId = getIntent().getIntExtra("ARTICLE_ID", -1);
        if (articleId != -1) {
            displayArticle(articleId);
        }
    }

    private void displayArticle(int id) {
        Cursor cursor = db.query("articles", null, "id=?", new String[]{String.valueOf(id)}, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            @SuppressLint("Range") String title = cursor.getString(cursor.getColumnIndex("title"));
            @SuppressLint("Range") String content = cursor.getString(cursor.getColumnIndex("content"));
            tvTitle.setText(title);
            tvContent.setText(content);
            cursor.close();
        }
    }
}
