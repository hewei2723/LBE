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
    // 当数据库版本更新时调用此方法
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // 如果users表存在，则删除
        db.execSQL("DROP TABLE IF EXISTS users");
        // 如果articles表存在，则删除
        db.execSQL("DROP TABLE IF EXISTS articles");
        // 重新创建数据库
        onCreate(db);
    }

    // 注册用户
    public boolean registerUser(String username, String password) {
        // 获取可写数据库
        SQLiteDatabase db = this.getWritableDatabase();
        // 创建ContentValues对象，用于存储要插入的数据
        ContentValues values = new ContentValues();
        // 将用户名和密码放入ContentValues对象中
        values.put("username", username);
        values.put("password", password);
        // 将数据插入到数据库中
        long result = db.insert("users", null, values);
        // 返回插入结果，如果插入成功，result不等于-1
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
        // 从数据库中查询所有用户信息
        Cursor userCursor = db.rawQuery("SELECT * FROM users", null);
        // 如果查询结果不为空，并且可以移动到第一行
        if (userCursor != null && userCursor.moveToFirst()) {
            // 循环遍历每一行
            do {
                // 获取用户ID
                @SuppressLint("Range") int id = userCursor.getInt(userCursor.getColumnIndex("id"));
                // 获取用户名
                @SuppressLint("Range") String username = userCursor.getString(userCursor.getColumnIndex("username"));
                // 获取密码
                @SuppressLint("Range") String password = userCursor.getString(userCursor.getColumnIndex("password"));
                // 打印用户信息
                Log.d(TAG, "User - ID: " + id + ", Username: " + username + ", Password: " + password);
            } while (userCursor.moveToNext());
            // 关闭游标
            userCursor.close();
        }

        // 查询articles表的数据
        // 从数据库中查询所有文章
        Cursor articleCursor = db.rawQuery("SELECT * FROM articles", null);
        // 如果查询结果不为空，并且可以移动到第一行
        if (articleCursor != null && articleCursor.moveToFirst()) {
            // 循环遍历每一行
            do {
                // 获取文章的id
                @SuppressLint("Range") int id = articleCursor.getInt(articleCursor.getColumnIndex("id"));
                // 获取文章的作者
                @SuppressLint("Range") String username = articleCursor.getString(articleCursor.getColumnIndex("username"));
                // 获取文章的标题
                @SuppressLint("Range") String title = articleCursor.getString(articleCursor.getColumnIndex("title"));
                // 获取文章的内容
                @SuppressLint("Range") String content = articleCursor.getString(articleCursor.getColumnIndex("content"));
                // 打印文章信息
                Log.d(TAG, "Article - ID: " + id + ", Username: " + username + ", Title: " + title + ", Content: " + content);
            } while (articleCursor.moveToNext());
            // 关闭游标
            articleCursor.close();
        }
    }
}
