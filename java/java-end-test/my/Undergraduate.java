//（2）本科生Undergraduate设计（20分）

import java.util.Date;
//        1）继承Student（2分）
public class Undergraduate extends Student {
    //        2）新增属性：专业（5分）
    private String major;
    //        3）构造器：Undergraduate(String name, String studentID, String gender, Date birthDate, String className, String major)（5分）
    public Undergraduate(String name, String studentID, String gender, Date birthDate, String className, String major) {
        super(name, studentID, gender, birthDate, className);
        this.major = major;
    }
    //        4）get方法、set方法（4分）
    public String getMajor() {
        return major;
    }
    public void setMajor(String major) {
        this.major = major;
    }
    //        5）重写toString方法：打印学生的所有属性信息（4分）
    public String toString() {
        return super.toString() + ", 主修: " + major;
    }
}