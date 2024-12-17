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
import java.util.ArrayList;
import java.util.List;
public class Login extends Fragment {
    // 使用@SuppressLint注解来抑制警告
    @SuppressLint("SetTextI18n")
    // 重写onCreateView方法
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        // 使用inflater将布局文件login.xml加载到视图中
        View view = inflater.inflate(R.layout.login, container, false);
        // 创建SqlDB对象
        SqlDB dbHelper = new SqlDB(getContext());
        // 获取SharedPreferences对象
        SharedPreferences preferences = requireActivity().getSharedPreferences("login_prefs", Context.MODE_PRIVATE);
        // 获取TextView对象
        TextView textUsername = view.findViewById(R.id.textView_username);
        // 用于显示"已发布的文章："
        // 获取文章标题文本框
        TextView textArticlesTitle = view.findViewById(R.id.textView_articles);
        // 获取注销按钮
        Button btnLogout = view.findViewById(R.id.button_logout);
        // 从 SharedPreferences 中获取用户名
        String username = preferences.getString("username", "未登录");
        // 设置用户名文本框内容
        textUsername.setText("当前登录账号：" + username);
        // 显示文章列表
        // 从数据库中获取指定用户的所有文章
        Cursor cursor = dbHelper.getUserArticles(username);
        // 创建一个列表用于存储文章标题
        List<String> articles = new ArrayList<>();
        // 遍历游标，获取每一篇文章的标题
        while (cursor.moveToNext()) {
            articles.add(cursor.getString(0)); // 获取文章标题
        }

        // 构建文章标题文本
        // 创建一个StringBuilder对象，用于存储文章文本
        StringBuilder articlesText = new StringBuilder();
        // 遍历文章列表
        for (String article : articles) {
            // 将每篇文章添加到StringBuilder对象中，并在每篇文章后面添加一个换行符
            articlesText.append(article).append("\n");
        }

        // 设置文章标题到TextView中
        textArticlesTitle.setText("已发布的文章：\n" + articlesText);

        // 退出登录
        btnLogout.setOnClickListener(v -> {
            preferences.edit().clear().apply(); // 清除登录状态
            Intent intent = new Intent(getActivity(), MainActivity.class); // 跳转到登录界面
            startActivity(intent);
            requireActivity().finish(); // 关闭当前界面
        });

        return view;
    }
}