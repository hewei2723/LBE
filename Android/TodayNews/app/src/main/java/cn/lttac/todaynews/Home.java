package cn.lttac.todaynews;

import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
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
        webView.loadUrl("https://www.lttac.cn"); // 加载新闻 URL
        new Thread(() -> {
            try {
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
                Thread.sleep(1000);
                getActivity().runOnUiThread(() -> updateUI(rootView, jsonResponse));
            } catch (Exception e) {
                e.printStackTrace();
                getActivity().runOnUiThread(() -> Toast.makeText(getActivity(), "加载失败", Toast.LENGTH_SHORT).show());
            }
        }).start();

        return rootView;
    }
    private void updateUI(View rootView, JSONArray newsData) {
        try {
            for (int i = 0; i < newsData.length(); i++) {
                JSONObject newsItem = newsData.getJSONObject(i);
                String title = newsItem.getString("title");
                String link = newsItem.getString("link");
                int resId = getResources().getIdentifier("news_title_" + (i + 1), "id", getActivity().getPackageName());
                TextView newsTitle = rootView.findViewById(resId);
                newsTitle.setText(title);
                newsTitle.setOnClickListener(v -> {
                    // 获取 WebView
                    WebView webView = rootView.findViewById(R.id.webview);
                    webView.setBackgroundColor(Color.TRANSPARENT);
                    webView.loadUrl(link); // 加载新闻 URL
                });
            }
        } catch (Exception e) {
            // 捕获异常
            e.printStackTrace();
            // 打印异常信息
            Toast.makeText(getActivity(), "更新失败", Toast.LENGTH_SHORT).show();
            // 弹出提示框，提示更新失败
        }
    }
}
