package cn.lttac.todaynews;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.fragment.app.Fragment;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class Home extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.home, container, false);
        WebView webView = rootView.findViewById(R.id.webview);
        webView.setBackgroundColor(Color.TRANSPARENT);
        WebSettings webSettings = webView.getSettings();
        webSettings.setMixedContentMode(WebSettings.MIXED_CONTENT_ALWAYS_ALLOW); // 允许混合内容加载

        // 在后台线程中获取数据
        new Thread(() -> {
            try {
                Thread.sleep(1000);
                URL url = new URL("http://news.api.lttac.cn/get_data");
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("GET");
                connection.setConnectTimeout(5000);
                connection.setReadTimeout(5000);
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    response.append(line);
                }
                JSONArray jsonResponse = new JSONArray(response.toString());
                // 更新UI
                if (getActivity() != null) {
                    getActivity().runOnUiThread(() -> updateUI(rootView, jsonResponse));
                }
            } catch (Exception e) {
                e.printStackTrace();
                // 确保在UI线程中执行
                if (getActivity() != null) {
                    getActivity().runOnUiThread(() -> Toast.makeText(getActivity(), "加载失败", Toast.LENGTH_SHORT).show());
                }
            }
        }).start();
        return rootView;
    }

    private void updateUI(View rootView, JSONArray newsData) {
        try {
            // 定义一个变量来保存第一个新闻链接
            String firstLink = null;

            // 遍历返回的新闻数据
            for (int i = 0; i < newsData.length(); i++) {
                JSONObject newsItem = newsData.getJSONObject(i);
                String title = newsItem.getString("title");
                String link = newsItem.getString("link");

                // 如果是第一个新闻，保存链接
                if (i == 0) {
                    firstLink = link;
                }

                // 获取动态生成的 TextView 控件 ID
                int resId = getResources().getIdentifier("news_title_" + (i + 1), "id", getActivity().getPackageName());
                TextView newsTitle = rootView.findViewById(resId);
                // 设置新闻标题
                newsTitle.setText(title);
                // 点击标题跳转到新闻链接
                newsTitle.setOnClickListener(v -> {
                    WebView webView = rootView.findViewById(R.id.webview);
                    webView.setBackgroundColor(Color.TRANSPARENT);
                    webView.loadUrl(link); // 加载新闻 URL
                });
            }

            // 如果第一个新闻链接存在，则加载该链接
            if (firstLink != null) {
                WebView webView = rootView.findViewById(R.id.webview);
                webView.setBackgroundColor(Color.TRANSPARENT);
                webView.loadUrl(firstLink); // 加载第一个新闻的链接
            }

        } catch (Exception e) {
            e.printStackTrace();
            // 捕获异常并显示错误信息
            if (getActivity() != null) {
                Toast.makeText(getActivity(), "更新失败", Toast.LENGTH_SHORT).show();
            }
        }
    }
}
