package cn.lttac.news;

import android.os.Bundle;
import android.text.TextUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class AddNews extends AppCompatActivity {

    private EditText etNewsContent;
    private Button btnPublish;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.addnews);  // 这里是设置 Activity 的布局

        // 绑定控件
        etNewsContent = findViewById(R.id.etNewsContent);
        btnPublish = findViewById(R.id.btnPublish);

        // 模拟登录状态检查
        boolean isLoggedIn = checkLoginStatus();

        // 发布按钮点击事件
        btnPublish.setOnClickListener(v -> {
            if (!isLoggedIn) {
                Toast.makeText(AddNews.this, "请先登录再发布新闻", Toast.LENGTH_SHORT).show();
                return;
            }

            String newsContent = etNewsContent.getText().toString().trim();
            if (TextUtils.isEmpty(newsContent)) {
                Toast.makeText(AddNews.this, "内容不能为空", Toast.LENGTH_SHORT).show();
            } else {
                // 发布成功逻辑
                Toast.makeText(AddNews.this, "发布成功：" + newsContent, Toast.LENGTH_SHORT).show();
                etNewsContent.setText(""); // 清空输入框
            }
        });
    }

    // 模拟登录状态检查
    private boolean checkLoginStatus() {
        // 这里可以用全局变量或 SharedPreferences 保存登录状态，示例为 false（未登录）
        return false; // 修改为 true 表示已登录
    }
}
