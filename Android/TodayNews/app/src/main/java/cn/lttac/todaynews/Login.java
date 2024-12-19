package cn.lttac.todaynews;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class Login extends Fragment {

    @SuppressLint("SetTextI18n")
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.login, container, false);
        SqlDB dbHelper = new SqlDB(getContext());
        SharedPreferences preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);

        // 获取控件
        TextView textUsername = view.findViewById(R.id.textView_username);
        TextView textArticlesTitle = view.findViewById(R.id.textView_articles); // 显示文章标题
        TextView text3 = view.findViewById(R.id.text3); // 显示文章内容
        Button btnLogout = view.findViewById(R.id.button_logout);

        // 获取当前用户名
        String username = preferences.getString("username", "未登录");
        textUsername.setText("当前登录账号：" + username);

        // 获取用户文章数据
        Cursor cursor = dbHelper.getUserArticles(username);
        StringBuilder articlesText = new StringBuilder();

        // 遍历游标并拼接标题和内容
        while (cursor.moveToNext()) {
            @SuppressLint("Range") String title = cursor.getString(cursor.getColumnIndex("title"));
            @SuppressLint("Range") String content = cursor.getString(cursor.getColumnIndex("content"));
            articlesText.append("标题: ").append(title).append("\n")
                    .append("内容: ").append(content).append("\n\n");
        }

        // 设置显示文章的TextView
        if (articlesText.length() > 0) {
            textArticlesTitle.setText("已发布的文章：");
            text3.setText(articlesText.toString());
        } else {
            textArticlesTitle.setText("暂无文章");
        }

        // 退出登录
        btnLogout.setOnClickListener(v -> {
            preferences.edit().clear().apply(); // 清除登录状态
            Intent intent = new Intent(getActivity(), MainActivity.class); // 跳转到登录界面
            startActivity(intent);
            requireActivity().finish(); // 关闭当前界面
        });

        // 关闭游标
        if (cursor != null) {
            cursor.close();
        }

        return view;
    }
}
