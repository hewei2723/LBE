package com.example.tour;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class says extends AppCompatActivity {
    private db dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);
        ImageView sceneImage = findViewById(R.id.overview_image);
        TextView sceneName = findViewById(R.id.scene_name);
        TextView sceneDescription = findViewById(R.id.scene_description);
        Intent intent = getIntent();
        String scene = intent.getStringExtra("scene_name");
        dbHelper = new db(this);
        if (scene != null) {
            loadSceneData(scene, sceneImage, sceneName, sceneDescription);
        }
    }

    private void loadSceneData(String sceneName, ImageView sceneImage, TextView sceneNameTextView, TextView sceneDescriptionTextView) {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + com.example.tour.db.TABLE_NAME + " WHERE " + com.example.tour.db.COLUMN_NAME + " = ?", new String[]{sceneName});
        if (cursor != null && cursor.moveToFirst()) {
            @SuppressLint("Range") String name = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_NAME));
            @SuppressLint("Range") String description = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_DESCRIPTION));
            @SuppressLint("Range") String imageName = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_IMAGE));
            Log.d("DetailActivity", "Name: " + name + ", Description: " + description + ", Image: " + imageName);
            sceneNameTextView.setText(name);
            sceneDescriptionTextView.setText(description);
            @SuppressLint("DiscouragedApi") int imageResId = getResources().getIdentifier(imageName, "drawable", getPackageName());
            sceneImage.setImageResource(imageResId);
            cursor.close();
        } else {
            Log.e("DetailActivity", "找不到这个景点 " + sceneName);
        }
        db.close();
    }
}
