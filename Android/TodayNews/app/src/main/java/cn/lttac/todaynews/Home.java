package cn.lttac.todaynews;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.TextView;
import androidx.fragment.app.Fragment;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Home extends Fragment {

    private List<String> newsTitles = new ArrayList<>();
    private List<String> newsLinks = new ArrayList<>();

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.home, container, false);

        // 知乎热榜的URL
        String url = "https://www.zhihu.com/billboard";

        new Thread(() -> {
            try {
                // 使用Jsoup连接并获取页面
                Document doc = Jsoup.connect(url).get();
                // 选择包含标题和链接的元素，这里假设标题在HotList-itemTitle类中，链接在link属性中
                Elements items = doc.select("div.HotList-item");

                for (Element item : items) {
                    // 获取标题
                    Element titleElement = item.selectFirst("div.HotList-itemTitle");
                    if (titleElement != null) {
                        String title = titleElement.text();
                        newsTitles.add(title);
                    }

                    // 获取链接
                    Element linkElement = item.selectFirst("a[href]");
                    if (linkElement != null) {
                        String link = linkElement.attr("abs:href"); // 获取绝对URL
                        newsLinks.add(link);
                    }
                }

                // 确保在主线程更新UI
                requireActivity().runOnUiThread(() -> updateUI(rootView));

            } catch (IOException e) {
                e.printStackTrace();
                // 这里应该处理异常，可能是网络问题或解析失败等
            }
        }).start();

        return rootView;
    }

    private void updateUI(View rootView) {
        // 这里假设你的布局中有最多显示5条新闻的TextView和一个WebView
        for (int i = 0; i < Math.min(5, newsTitles.size()); i++) {
            int resId = getResources().getIdentifier("news_title_" + (i + 1), "id", getActivity().getPackageName());
            TextView newsTitle = rootView.findViewById(resId);
            newsTitle.setText(newsTitles.get(i));

            int finalI = i;
            newsTitle.setOnClickListener(v -> {
                WebView webView = rootView.findViewById(R.id.webview);
                webView.loadUrl(newsLinks.get(finalI));
            });
        }
    }
}