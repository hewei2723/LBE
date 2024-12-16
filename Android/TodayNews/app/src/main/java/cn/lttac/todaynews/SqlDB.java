package cn.lttac.todaynews;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

public class SqlDB extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "newsApp.db";
    private static final int DATABASE_VERSION = 1;

    private static final String TAG = "DatabaseHelper";

    public SqlDB(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT UNIQUE, password TEXT)");
        db.execSQL("CREATE TABLE articles (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, title TEXT, content TEXT)");
    }//这里得给username传进去，不然找不到用户的文章

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS users");
        db.execSQL("DROP TABLE IF EXISTS articles");
        onCreate(db);
    }

    public boolean registerUser(String username, String password) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("username", username);
        values.put("password", password);
        long result = db.insert("users", null, values);
        return result != -1;
    }

    public boolean loginUser(String username, String password) {
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.rawQuery("SELECT * FROM users WHERE username=? AND password=?", new String[]{username, password});
        return cursor.moveToFirst();
    }

    public Cursor getUserArticles(String username) {
        SQLiteDatabase db = this.getReadableDatabase();
        return db.rawQuery("SELECT title FROM articles WHERE username=?", new String[]{username});
    }

    // 新增的函数，用于打印所有表的数据到log
    public void logAllData() {
        SQLiteDatabase db = this.getReadableDatabase();

        // 查询users表的数据
        Cursor userCursor = db.rawQuery("SELECT * FROM users", null);
        if (userCursor != null && userCursor.moveToFirst()) {
            do {
                @SuppressLint("Range") int id = userCursor.getInt(userCursor.getColumnIndex("id"));
                @SuppressLint("Range") String username = userCursor.getString(userCursor.getColumnIndex("username"));
                @SuppressLint("Range") String password = userCursor.getString(userCursor.getColumnIndex("password"));
                Log.d(TAG, "User - ID: " + id + ", Username: " + username + ", Password: " + password);
            } while (userCursor.moveToNext());
            userCursor.close();
        }

        // 查询articles表的数据
        Cursor articleCursor = db.rawQuery("SELECT * FROM articles", null);
        if (articleCursor != null && articleCursor.moveToFirst()) {
            do {
                @SuppressLint("Range") int id = articleCursor.getInt(articleCursor.getColumnIndex("id"));
                @SuppressLint("Range") String username = articleCursor.getString(articleCursor.getColumnIndex("username"));
                @SuppressLint("Range") String title = articleCursor.getString(articleCursor.getColumnIndex("title"));
                @SuppressLint("Range") String content = articleCursor.getString(articleCursor.getColumnIndex("content"));
                Log.d(TAG, "Article - ID: " + id + ", Username: " + username + ", Title: " + title + ", Content: " + content);
            } while (articleCursor.moveToNext());
            articleCursor.close();
        }
    }
}
