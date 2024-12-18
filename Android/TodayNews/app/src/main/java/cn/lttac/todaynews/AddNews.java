package cn.lttac.todaynews;
import android.content.ContentValues;
import android.content.Context;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.fragment.app.Fragment;

import java.util.Objects;

public class AddNews extends Fragment {
    private SqlDB dbHelper;
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // 从布局文件中获取根视图
        View rootView = inflater.inflate(R.layout.addnews, container, false);
        // 获取SharedPreferences对象
        SharedPreferences preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);
        // 获取用户名
        String username = preferences.getString("username", "未登录");
        //如果没有用户名就返回未登录
        // 创建数据库帮助类对象
        dbHelper = new SqlDB(getActivity());
        // 获取标题输入框
        EditText titleEditText = rootView.findViewById(R.id.edit_title);
        // 获取内容输入框
        EditText contentEditText = rootView.findViewById(R.id.edit_content);
        // 获取发布按钮
        Button publishButton = rootView.findViewById(R.id.publish_button);

        // 设置发布按钮的点击事件
        publishButton.setOnClickListener(v -> {
            // 获取标题输入框的内容
            String title = titleEditText.getText().toString();
            // 获取内容输入框的内容
            String content = contentEditText.getText().toString();
            // 调用发布文章的方法，传入用户名、标题和内容
            publishArticle(username,title, content);
        });

        return rootView;
    }
    // 发布文章
    private void publishArticle(String username, String title, String content) {
        // 获取可写的数据库
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        // 创建ContentValues对象，用于存储数据
        ContentValues values = new ContentValues();
        // 将用户名、标题、内容存入ContentValues对象
        values.put("username", username);
        values.put("title", title);
        values.put("content", content);

        // 判断用户是否已登录
        if (!Objects.equals(username, "未登录")) {
            // 如果已登录，则将文章插入数据库
            db.insert("articles", null, values);
            // 记录所有数据
            // 弹出提示框，提示发布成功
            Toast.makeText(getContext(), "发布成功,请到我的页面查看文章标题", Toast.LENGTH_SHORT).show();
        } else {
            // 如果未登录，则弹出提示框，提示请登录
            Toast.makeText(getContext(), "请登录", Toast.LENGTH_SHORT).show();
        }
    }

}
