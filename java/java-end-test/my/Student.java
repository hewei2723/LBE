//（1）学生父类Student设计（30分）
//        1）属性：姓名、学号、性别、出生日期、班级（6分）
//        2）构造器：Student(String name, String studentID, String gender, Date birthDate, String className)（6分）
//        3）get方法、set方法（6分）
//        4）重写toString方法：打印学生的所有属性信息（6分）
//        5）重写equals函数：实现比较两位学生的学号是否相同，如果相同则返回true，否则返回false（6分）
import java.util.Date;
import java.util.Objects;
public class Student {
    private String name;
    private String studentID;
    private String gender;
    private Date birthDate;
    private String className;

    public Student(String name, String studentID, String gender, Date birthDate, String className)
    {
        this.name = name;
        this.studentID = studentID;
        this.gender = gender;
        this.birthDate = birthDate;
        this.className = className;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getStudentID()
    {
        return studentID;
    }

    public void setStudentID(String studentID)
    {
        this.studentID = studentID;
    }

    public String getGender()
    {
        return gender;
    }

    public void setGender(String gender)
    {
        this.gender = gender;
    }

    public Date getBirthDate()
    {
        return birthDate;
    }

    public void setBirthDate(Date birthDate)
    {
        this.birthDate = birthDate;
    }

    public String getClassName()
    {
        return className;
    }

    public void setClassName(String className)
    {
        this.className = className;
    }
    public String toString()
    {
        return "名字: " + name + ", 学号: " + studentID + ", 性别: " + gender + ",生日: " + birthDate + ", 班级: " + className;
    }
    public boolean equals(Object first) {
        if (this == first) return true;
        if (first == null || getClass() != first.getClass())
            return false;
        Student student = (Student) first;
        return Objects.equals(studentID, student.studentID);
    }
}
