package cn.lttac.eat;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
public class SQLiteHelper extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "FoodDatabase.db";
    private static final int DATABASE_VERSION = 1;

    public static final String TABLE_FOOD = "Food";
    public static final String COLUMN_NAME = "name";
    public static final String COLUMN_DESCRIPTION = "description";

    public SQLiteHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String CREATE_TABLE = "CREATE TABLE " + TABLE_FOOD + " (" +
                COLUMN_NAME + " TEXT PRIMARY KEY, " +
                COLUMN_DESCRIPTION + " TEXT)";
        db.execSQL(CREATE_TABLE);

        // 初始化数据
        insertFoodData(db);
    }

    public void insertFoodData(SQLiteDatabase db) {
        ContentValues values = new ContentValues();
        values.put(COLUMN_NAME, "牛排");
        values.put(COLUMN_DESCRIPTION, "可以在营火上放置生牛肉获得，也可以通过使用熔炉或烟熏炉烧制而成。屠夫村民可能会向带有村庄英雄增益的玩家投掷牛排。 牛排也可能会作为试炼刷怪笼完成的奖励。");
        db.insert(TABLE_FOOD, null, values);

        values.put(COLUMN_NAME, "附魔金苹果");
        values.put(COLUMN_DESCRIPTION, "附魔金苹果是金苹果的变种，它比较稀有，但可以给予较强的效果。");
        db.insert(TABLE_FOOD, null, values);

        values.put(COLUMN_NAME, "谜之炖菜");
        values.put(COLUMN_DESCRIPTION, "谜之炖菜将给予以下效果中的一种：5-7秒的失明、7-10秒的跳跃提升、7-10秒的夜视、10-20秒的中毒、7-10游戏刻的饱和或6-8秒的虚弱。");
        db.insert(TABLE_FOOD, null, values);

        values.put(COLUMN_NAME, "牛奶");
        values.put(COLUMN_DESCRIPTION, "奶桶是一种通过牛、哞菇或山羊来收集的物品。它也是原版Minecraft中营养价值最低的食物，所增加的饥饿值和饱和度都为0。");
        db.insert(TABLE_FOOD, null, values);

        values.put(COLUMN_NAME, "蜂蜜瓶");
        values.put(COLUMN_DESCRIPTION, "手持空的玻璃瓶，右击充满蜂蜜的蜂巢或蜂箱即可获得蜂蜜瓶。 饮用蜂蜜可恢复饥饿值和饱和度，同时消除玩家身上的中毒效果。玩家饥饿值已满时同样可以饮用蜂蜜。");
        db.insert(TABLE_FOOD, null, values);

        values.put(COLUMN_NAME, "蜘蛛眼");
        values.put(COLUMN_DESCRIPTION, "蜘蛛眼（Spider eye）是一种有毒的食物，也是一种酿造材料[1]，食用后获得4秒的中毒DEBUFF。蜘蛛眼还可以用来合成发酵蛛眼，还可以用来酿造平凡的药水和剧毒药水。");
        db.insert(TABLE_FOOD, null, values);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_FOOD);
        onCreate(db);
    }

    @SuppressLint("Range")
    public String getFoodDescription(String foodName) {
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.query(TABLE_FOOD, new String[]{COLUMN_DESCRIPTION}, COLUMN_NAME + "=?", new String[]{foodName}, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            return cursor.getString(cursor.getColumnIndex(COLUMN_DESCRIPTION));
        }
        return null;
    }
}
