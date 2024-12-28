package cn.lttac.tour;

import android.annotation.SuppressLint;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;

public class DetailActivity extends AppCompatActivity {

    private DatabaseHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);
        ImageView sceneImage = findViewById(R.id.overview_image);
        TextView sceneName = findViewById(R.id.scene_name);
        TextView sceneDescription = findViewById(R.id.scene_description);
        Intent intent = getIntent();
        String scene = intent.getStringExtra("scene_name");
        dbHelper = new DatabaseHelper(this);

        if (scene != null) {
            loadSceneData(scene, sceneImage, sceneName, sceneDescription);
        }
    }
    private void loadSceneData(String sceneName, ImageView sceneImage, TextView sceneNameTextView, TextView sceneDescriptionTextView) {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + DatabaseHelper.TABLE_NAME + " WHERE " +
                DatabaseHelper.COLUMN_NAME + " = ?", new String[]{sceneName});

        if (cursor != null && cursor.moveToFirst()) {
            @SuppressLint("Range") String name = cursor.getString(cursor.getColumnIndex(DatabaseHelper.COLUMN_NAME));
            @SuppressLint("Range") String description = cursor.getString(cursor.getColumnIndex(DatabaseHelper.COLUMN_DESCRIPTION));
            @SuppressLint("Range") String imageName = cursor.getString(cursor.getColumnIndex(DatabaseHelper.COLUMN_IMAGE));
            Log.d("DetailActivity", "Name: " + name + ", Description: " + description + ", Image: " + imageName);
            sceneNameTextView.setText(name);
            sceneDescriptionTextView.setText(description);
            int imageResId = getResources().getIdentifier(imageName, "drawable", getPackageName());
            if (imageResId == 0) {
                Log.e("DetailActivity", "图片走丢了 " + imageName);
                sceneImage.setImageResource(R.drawable.t1); // 默认图片
            } else {
                sceneImage.setImageResource(imageResId);
            }

            cursor.close();
        } else {
            Log.e("DetailActivity", "找不到这个景点 " + sceneName);
        }

        db.close();
}
}
