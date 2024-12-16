package cn.lttac.todaynews;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.TextView;
import androidx.fragment.app.Fragment;

public class Home extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.home, container, false);

        // 假设新闻标题数据
        String[] newsTitles = {
                "新闻标题 1", "新闻标题 2", "新闻标题 3", "新闻标题 4", "新闻标题 5"
        };

        // 新闻标题显示（最多显示 5 条）
        for (int i = 0; i < newsTitles.length; i++) {
            int resId = getResources().getIdentifier("news_title_" + (i + 1), "id", getActivity().getPackageName());
            TextView newsTitle = rootView.findViewById(resId);
            newsTitle.setText(newsTitles[i]);

            int finalI = i;
            newsTitle.setOnClickListener(v -> {
                WebView webView = rootView.findViewById(R.id.webview);
                webView.loadUrl("http://example.com/news/" + (finalI + 1)); // 示例 URL
            });
        }

        return rootView;
    }
}
