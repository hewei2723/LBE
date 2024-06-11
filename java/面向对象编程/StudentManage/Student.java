package StudentManage;

public class Student {
    String sno;
    String sname;
    String ssex;
    int sage;
    String sdept;

    // 默认无参构造函数
    public Student() {
    }

    public Student(String sno, String sname, String ssex, int sage, String sdept) {
        this.sno = sno;
        this.sname = sname;
        this.ssex = ssex;
        this.sage = sage;
        this.sdept = sdept;
    }
}
