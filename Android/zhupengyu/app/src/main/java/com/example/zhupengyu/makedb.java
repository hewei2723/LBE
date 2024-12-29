package com.example.zhupengyu;
import android.content.ContentValues;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
public class makedb extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "app.db";
    private static final int DATABASE_VERSION = 1;
    public makedb(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }
    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT NOT NULL, password TEXT NOT NULL);");
        db.execSQL("CREATE TABLE articles (id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT NOT NULL, content TEXT NOT NULL);");
        ContentValues userValues = new ContentValues();
        userValues.put("username", "朱鹏宇");
        userValues.put("password", "2022060404");
        db.insert("users", null, userValues);
        // 插入初始化的文章数据
        insertArticle(db, 1, "英伟达推出 GB200 NVL4 平台", "IT之家 12 月 26 日消息，英伟达为满足现代数据中心对高性能和可扩展性的需求，最新推出了 GB200 NVL4 平台，采用 Arm 架构，具备强大的计算能力并重点优化功耗，为 AI、高性能计算和其他计算密集型任务提供理想的解决方案。");
        insertArticle(db, 2, "小米 REDMIBook 14/16 2025 笔记本", "IT之家 12 月 28 日消息，小米 REDMI Book 14/16 2025 笔记本将于下个月发布，现在这两款新品均已上架京东平台并开启预约，SKU 也随着曝光");
        insertArticle(db, 3, "曝特斯拉Model Y已开始限制配件采购", "【CNMO科技消息】近日，汽车博主“胖虎Shawn”透露，当前特斯拉Model Y日产量为600多台，其中三分之一的产能为焕新版。同时，现款Model Y的配件采购已经开始受到限制，这表明特斯拉正在为新款Model Y的量产做充分准备。");
        insertArticle(db, 4, "两大芯片巨头反目，ARM输的彻底，高通大胜利！", "从目前的情况来看，全球最成功的芯片架构，并不是X86，也不是RISC-V，而是ARM。 因为智能手机时代的到来，让ARM火得飞起，一举拿下了智能手机市场几乎100%的份额，然后再从手机芯片不停的往外拓展，发展到物联网、汽车、PC等等产业。目前ARM架构，已经向X86发起猛攻，甚至表示要在未来几年，拿走AI PC 50%以上的份额。");
    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS users");
        db.execSQL("DROP TABLE IF EXISTS articles");
        onCreate(db);
    }
    private void insertArticle(SQLiteDatabase db, int id, String title, String content) {
        ContentValues values = new ContentValues();
        values.put("id", id);
        values.put("title", title);
        values.put("content", content);
        db.insert("articles", null, values);
    }
}
