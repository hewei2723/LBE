package com.example.tour;
import android.annotation.SuppressLint;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.VideoView;
import android.net.Uri;
import android.media.MediaPlayer;
import androidx.appcompat.app.AppCompatActivity;
public class says extends AppCompatActivity {
    private db dbHelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);
        VideoView sceneVideo = findViewById(R.id.overview_video);
        TextView sceneName = findViewById(R.id.scene_name);
        TextView sceneDescription = findViewById(R.id.scene_description);
        Intent intent = getIntent();
        String scene = intent.getStringExtra("scene_name");
        dbHelper = new db(this);
        if (scene != null) {
            loadSceneData(scene, sceneVideo, sceneName, sceneDescription);
        }
    }
    private void loadSceneData(String sceneName, VideoView sceneVideo, TextView sceneNameTextView, TextView sceneDescriptionTextView) {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM " + com.example.tour.db.TABLE_NAME + " WHERE " + com.example.tour.db.COLUMN_NAME + " = ?", new String[]{sceneName});
        if (cursor != null && cursor.moveToFirst()) {
            @SuppressLint("Range") String name = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_NAME));
            @SuppressLint("Range") String description = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_DESCRIPTION));
            @SuppressLint("Range") String videoName = cursor.getString(cursor.getColumnIndex(com.example.tour.db.COLUMN_IMAGE)); // 这里改成视频名称
            Log.d("DetailActivity", "Name: " + name + ", Description: " + description + ", Video: " + videoName);
            sceneNameTextView.setText(name);
            sceneDescriptionTextView.setText(description);
            String videoPath = "android.resource://" + getPackageName() + "/raw/" + videoName;
            Uri videoUri = Uri.parse(videoPath);
            sceneVideo.setVideoURI(videoUri);
            sceneVideo.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
                @Override
                public void onPrepared(MediaPlayer mp) {
                    mp.setLooping(true);
                    sceneVideo.start();
                }
            });
            cursor.close();
        } else {
            Log.e("DetailActivity", "找不到这个景点 " + sceneName);
        }
        db.close();
    }
}
