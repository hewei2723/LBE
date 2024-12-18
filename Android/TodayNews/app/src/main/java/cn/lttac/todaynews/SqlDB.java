package cn.lttac.todaynews;
import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class SqlDB extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "newsApp.db";
    private static final int DATABASE_VERSION = 1;
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
        @SuppressLint("Recycle") Cursor cursor = db.rawQuery("SELECT * FROM users WHERE username=? AND password=?", new String[]{username, password});
        return cursor.moveToFirst();
    }

    public Cursor getUserArticles(String username) {
        SQLiteDatabase db = this.getReadableDatabase();
        return db.rawQuery("SELECT title,content FROM articles WHERE username=?", new String[]{username});
    }
}
