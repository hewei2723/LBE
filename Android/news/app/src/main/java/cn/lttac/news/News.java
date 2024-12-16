package cn.lttac.news;

public class News {
    private final String title;
    private final String content;
    public News(String title, String content) {
        this.title = title;
        this.content = content;
    }
    public String getTitle() {
        return title;
    }
    public String getContent() {
        return content;
    }
}
