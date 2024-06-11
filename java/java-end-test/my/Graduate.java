//研究生Graduate设计（20分）
//继承Student（2分）
//增属性：导师、研究方向（5分）
//构造器：Graduate(String name, String studentID, String gender, Date birthDate, String className, String advisor, String researchField)（5分）
//get方法、set方法（4分）
//重写toString方法：打印学生的所有属性信息（4分）
import java.util.Date;
public class Graduate extends Student
{
    private String advisor;
    private String researchField;
    public Graduate(String name, String studentID, String gender, Date birthDate, String className, String advisor, String researchField) {
        super(name, studentID, gender, birthDate, className);
        this.advisor = advisor;//导师的英文
        this.researchField = researchField;
    }
    public String getAdvisor()
    {
        return advisor;
    }
    public void setAdvisor(String advisor)
    {
        this.advisor = advisor;
    }
    public String getResearchField()
    {
        return researchField;
    }
    public void setResearchField(String researchField)
    {
        this.researchField = researchField;
    }
    public String toString()
    {
        return super.toString() + ", 导师: " + advisor + ", 研究方向: " + researchField;
    }
}
