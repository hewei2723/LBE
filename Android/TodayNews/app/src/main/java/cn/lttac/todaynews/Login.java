package cn.lttac.todaynews;
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

import java.util.ArrayList;
import java.util.List;

public class Login extends Fragment {

    private TextView textUsername;
    private TextView textArticlesTitle; // 用于显示"已发布的文章："
    private Button btnLogout;
    private SqlDB dbHelper;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.login, container, false);

        dbHelper = new SqlDB(getContext());
        SharedPreferences preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);
        textUsername = view.findViewById(R.id.textView_username);
        textArticlesTitle = view.findViewById(R.id.textView_articles);
        btnLogout = view.findViewById(R.id.button_logout);

        // 从 SharedPreferences 中获取用户名
        String username = preferences.getString("username", "未登录");
        textUsername.setText("当前登录账号：" + username);

        // 显示文章列表
        Cursor cursor = dbHelper.getUserArticles(username);
        List<String> articles = new ArrayList<>();
        while (cursor.moveToNext()) {
            articles.add(cursor.getString(0)); // 获取文章标题
        }

        // 构建文章标题文本
        StringBuilder articlesText = new StringBuilder();
        for (String article : articles) {
            articlesText.append(article).append("\n");
        }

        // 设置文章标题到TextView中
        textArticlesTitle.setText("已发布的文章：\n" + articlesText);

        // 退出登录
        btnLogout.setOnClickListener(v -> {
            preferences.edit().clear().apply(); // 清除登录状态
            Intent intent = new Intent(getActivity(), MainActivity.class); // 跳转到登录界面
            startActivity(intent);
            requireActivity().finish();
        });

        return view;
    }
}