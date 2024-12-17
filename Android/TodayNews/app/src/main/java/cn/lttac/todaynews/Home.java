package cn.lttac.todaynews;
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
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.net.HttpURLConnection;
import java.net.URL;
public class Home extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.home, container, false);
        // 启动线程请求新闻数据
        new Thread(() -> {
            try {
                // 请求新闻数据的 URL
                URL url = new URL("http://news.api.lttac.cn/get_data");
                // 创建一个HttpURLConnection对象，用于连接指定的URL
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                // 设置请求方法为GET
                connection.setRequestMethod("GET");
                // 设置连接超时时间为5秒
                connection.setConnectTimeout(5000);
                // 设置读取超时时间为5秒
                connection.setReadTimeout(5000);
                // 获取响应
                // 创建一个BufferedReader对象，用于读取从连接中获取的输入流
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                // 创建一个StringBuilder对象，用于存储读取到的数据
                StringBuilder response = new StringBuilder();
                // 定义一个字符串变量，用于存储读取到的每一行数据
                String line;
                // 循环读取每一行数据，直到读取完毕
                while ((line = reader.readLine()) != null) {
                    // 将读取到的每一行数据添加到StringBuilder对象中
                    response.append(line);
                }
                // 解析 JSON 响应
                // 将response转换为JSONArray对象
                JSONArray jsonResponse = new JSONArray(response.toString());
                // 在主线程中更新UI
                getActivity().runOnUiThread(() -> updateUI(rootView, jsonResponse));
            } catch (Exception e) {
                // 打印异常信息
                e.printStackTrace();
                // 在主线程中显示加载失败的提示
                getActivity().runOnUiThread(() -> Toast.makeText(getActivity(), "加载失败", Toast.LENGTH_SHORT).show());
            }
        }).start();

        return rootView;
    }
    // 更新 UI
    private void updateUI(View rootView, JSONArray newsData) {
        try {
            // 遍历新闻数据并更新界面
            // 遍历新闻数据
            for (int i = 0; i < newsData.length(); i++) {
                // 获取新闻数据中的每一个新闻项
                JSONObject newsItem = newsData.getJSONObject(i);
                // 获取新闻项中的标题
                String title = newsItem.getString("title");
                // 获取新闻项中的链接
                String link = newsItem.getString("link");

                // 获取资源 ID
                int resId = getResources().getIdentifier("news_title_" + (i + 1), "id", getActivity().getPackageName());
                // 通过资源 ID 获取 TextView
                TextView newsTitle = rootView.findViewById(resId);
                // 设置 TextView 的文本
                newsTitle.setText(title);
                // 设置 TextView 的点击事件
                newsTitle.setOnClickListener(v -> {
                    // 获取 WebView
                    WebView webView = rootView.findViewById(R.id.webview);
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
