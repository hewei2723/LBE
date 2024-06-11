//（4）接口设计（10分）
//学生信息管理接口，接口中有获取所有学生信息的方法（10分）
public class StudentManagement implements info  {
    private Undergraduate[] undergraduates;
    private Graduate[] graduates;
    private int benNum;//本科生
    private int yanNum;//研究生

    public StudentManagement(int num) {
        undergraduates = new Undergraduate[num];
        graduates = new Graduate[num];
        benNum = 0;
        yanNum = 0;
    }

    public void addUndergraduate(Undergraduate student) {
        if (benNum < undergraduates.length) {
            undergraduates[benNum++] = student;
        } else {
            System.out.println("抱歉，今年的本科生名额满啦");
        }
    }

    public void addGraduate(Graduate student) {
        if (yanNum < graduates.length) {
            graduates[yanNum++] = student;
        } else {
            System.out.println("抱歉，今年的研究生名额满啦");
        }
    }

    public void delStudent(String studentID) {
        for (int i = 0; i < benNum; i++) {
            if (undergraduates[i].getStudentID().equals(studentID)) {
                undergraduates[i] = undergraduates[--benNum];
                undergraduates[benNum] = null;
                return;
            }
        }

        for (int i = 0; i < yanNum; i++) {
            if (graduates[i].getStudentID().equals(studentID)) {
                graduates[i] = graduates[--yanNum];
                graduates[yanNum] = null;
                return;
            }
        }
    }
    public void getAllStudentInfo() {
        System.out.println("本科生信息如下：");
        for (int i = 0; i < benNum; i++) {
            System.out.println(undergraduates[i]);
        }
        System.out.println("研究生信息如下：");
        for (int i = 0; i < yanNum; i++) {
            System.out.println(graduates[i]);
        }
    }
}

