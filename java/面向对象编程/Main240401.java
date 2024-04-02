class Student {
    private String Sno;
    private String Sname;
    private String Ssex;
    private int Sage;
    private String Sdept;

    public Student(String Sno, String Sname, String Ssex, int Sage, String Sdept) {
        this.Sno = Sno;
        this.Sname = Sname;
        this.Ssex = Ssex;
        this.Sage = Sage;
        this.Sdept = Sdept;
    }

    public String getSno() {
        return Sno;
    }

    public String getSname() {
        return Sname;
    }

    public String getSsex() {
        return Ssex;
    }

    public int getSage() {
        return Sage;
    }

    public String getSdept() {
        return Sdept;
    }
}
class Course {
    private int Cno;
    private String Cname;
    private int Cpno;
    // 假设Cpno表示先修课的编号
    private int Ccredit;

    // 假设Ccredit表示学分
    public Course(int Cno, String Cname, int Cpno, int Ccredit) {
        this.Cno = Cno;
        this.Cname = Cname;
        this.Cpno = Cpno;
        this.Ccredit = Ccredit;
    }

    public int getCno() {
        return Cno;
    }

    public String getCname() {
        return Cname;
    }

    public int getCpno() {
        return Cpno;
    }

    public int getCcredit() {
        return Ccredit;
    }
}

class SC {
    private String Sno;
    private int Cno;
    private int Grade;

    public SC(String Sno, int Cno, int Grade) {
        this.Sno = Sno;
        this.Cno = Cno;
        this.Grade = Grade;
    }

    public String getSno() {
        return Sno;
    }
    public int getCno() {
        return Cno;
    }
    public int getGrade() {
        return Grade;
    }
}
public class Main240401 {
    public static void main(String[] args) {
        // 创建学生对象
        Student student1 = new Student("201015121", "李勇", "男", 20, "cs");
        Student student2 = new Student("201015122", "刘晨", "女", 19, "cs");
        Student student3 = new Student("201015123", "王敏", "女", 18, "ma");
        Student student4 = new Student("201015125", "张立", "男", 19, "is");

        // 创建课程对象
        Course course1 = new Course(1, "数据库", 5, 4);
        Course course2 = new Course(2, "数学", 0, 3);
        Course course3 = new Course(3, "信息系统", 0, 2);
        Course course4 = new Course(4, "操作系统", 0, 4);
        Course course5 = new Course(5, "数据结构", 0, 4);
        Course course6 = new Course(6, "数据处理", 0, 2);
        Course course7 = new Course(7, "PASCAL语言", 0, 4);

        // 创建成绩对象
        SC sc1 = new SC("201015121", 1, 92);
        SC sc2 = new SC("201015121", 2, 85);
        SC sc3 = new SC("201015121", 3, 88);
        SC sc4 = new SC("201015122", 2, 90);
        SC sc5 = new SC("201015122", 3, 80);

        // 输出学生信息
        System.out.println("学生信息：");
        System.out.println("学号\t        姓名\t性别\t年龄\t所在系");
        System.out.println(student1.getSno() + "\t" + student1.getSname() + "\t" + student1.getSsex() + "\t" + student1.getSage() + "\t" + student1.getSdept());
        System.out.println(student2.getSno() + "\t" + student2.getSname() + "\t" + student2.getSsex() + "\t" + student2.getSage() + "\t" + student2.getSdept());
        System.out.println(student3.getSno() + "\t" + student3.getSname() + "\t" + student3.getSsex() + "\t" + student3.getSage() + "\t" + student3.getSdept());
        System.out.println(student4.getSno() + "\t" + student4.getSname() + "\t" + student4.getSsex() + "\t" + student4.getSage() + "\t" + student4.getSdept());

        // 输出课程信息
        System.out.println("课程信息：");
        System.out.println("课程号  课程名\t先行课\t学分");
        System.out.println(course1.getCno() + " \t" + course1.getCname() + "\t" + course1.getCpno() + "\t" + course1.getCcredit());
        System.out.println(course2.getCno() + " \t" + course2.getCname() + "\t" + course2.getCpno() + "\t" + course2.getCcredit());
        System.out.println(course3.getCno() + " \t" + course3.getCname() + "\t" + course3.getCpno() + "\t" + course3.getCcredit());
        System.out.println(course4.getCno() + " \t" + course4.getCname() + "\t" + course4.getCpno() + "\t" + course4.getCcredit());
        System.out.println(course5.getCno() + " \t" + course5.getCname() + "\t" + course5.getCpno() + "\t" + course5.getCcredit());
        System.out.println(course6.getCno() + " \t" + course6.getCname() + "\t" + course6.getCpno() + "\t" + course6.getCcredit());
        System.out.println(course7.getCno() + " \t" + course7.getCname() + "\t" + course7.getCpno() + "\t" + course7.getCcredit());

        // 输出学生成绩信息
        System.out.println("学生成绩信息：");
        System.out.println("姓名\t学号\t课程号\t成绩");
        System.out.println(student1.getSname() + "\t" + sc1.getSno() + "\t" + sc1.getCno()+ "\t" + sc1.getGrade());
        System.out.println(student1.getSname() + "\t" + student1.getSno() + "\t" + sc2.getCno()+ "\t" + sc2.getGrade());
        System.out.println(student2.getSname() + "\t" + student2.getSno() + "\t" + sc3.getCno()+ "\t" + sc3.getGrade());
        System.out.println(student2.getSname() + "\t" + student2.getSno() + "\t" + sc2.getCno()+ "\t" + sc2.getGrade());
        System.out.println(student2.getSname() + "\t" + student2.getSno() + "\t" + sc3.getCno()+ "\t" + sc4.getGrade());
    }
}