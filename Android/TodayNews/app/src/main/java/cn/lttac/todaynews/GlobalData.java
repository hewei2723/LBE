package cn.lttac.todaynews;

// 定义全局数据管理的单例类
public class GlobalData {
    private static GlobalData instance;
    private String username;

    private GlobalData() {} // 私有构造函数

    public static GlobalData getInstance() {
        if (instance == null) {
            instance = new GlobalData();
        }
        return instance;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }
}
