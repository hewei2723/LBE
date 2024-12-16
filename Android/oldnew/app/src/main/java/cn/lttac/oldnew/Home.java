package cn.lttac.oldnew;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.Arrays;
import java.util.List;

public class Home extends AppCompatActivity {

    private RecyclerView recyclerView;
    private NewsAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_notifications);  // 设置 Activity 布局

        // 初始化 RecyclerView
        recyclerView = findViewById(R.id.newsRecyclerView);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));

        // 模拟新闻数据
        List<String> newsList = Arrays.asList("新闻1", "新闻2", "新闻3", "新闻4");

        // 设置适配器
        adapter = new NewsAdapter(newsList);
        recyclerView.setAdapter(adapter);
    }
}
