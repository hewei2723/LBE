package cn.lttac.todaynews;
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
}
