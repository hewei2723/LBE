<<<<<<< HEAD
import java.io.FileOutputStream;
=======
package src;
>>>>>>> 3d0f848d3983c712f504f0e8e2825c3acc2e88d6
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
<<<<<<< HEAD
imp
// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
=======
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
>>>>>>> 3d0f848d3983c712f504f0e8e2825c3acc2e88d6
public class Main {
    public static void main(String[] args) {
        Spider s = new Spider("https://www.meijutt.net/alltop_hit.html");
        Document doc = s.downloadHtml();
        String content = doc.toString();

        // 通过正则表达式匹配电影名称和链接
        String regex = "<a href=\"(.*?)\" title=\"(.*?)\"";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(content);
        while (matcher.find()) {
            String matchedUrl = matcher.group(1);
            String matchedTitle = matcher.group(2);
            System.out.println("电影名: " + matchedTitle + " 链接： https://www.meijutt.net/" + matchedUrl);
        }

        // 示例代码，用于下载图片
        /*
        for (int i = 1; i < 100; i++) {
            Spider s = new Spider("https://www.qimao.com/shuku/a-2-16-a-a-a-a-click-" + i + "/");

            Document doc = s.downloadHtml();
            String content = doc.toString();
            String regex = "src=\"(https://.*?.jpg)\"[\\s\\S]{1,150}href=\".{1,50}?\">(.{1,20}?)</a></span>";
            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(content);
            while (matcher.find()) {
                String matched = matcher.group(1);
                String matchedTitle = matcher.group(2);
                try {
                    s.downloadImage(matched, matchedTitle + ".jpg");
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }
        */
    }
}

class Spider {
    private final String url;

    public Spider(String url) {
        this.url = url;
    }

    public Document downloadHtml() {
        try {
            // 设置 User-Agent
            String userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (HTML, like Gecko) Chrome/123.0.0.0 Safari/537.36";
            return Jsoup.connect(url)
                    .userAgent(userAgent) // 设置 User-Agent
                    .get();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
