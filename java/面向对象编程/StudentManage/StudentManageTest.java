package StudentManage;

public class StudentManageTest {
    public static void main(String[] args) {
        //2、在测试类中创建学生数组存储学生对象，打印数组中每个学生的信息。
        System.out.println("2、在测试类中创建学生数组存储学生对象，打印数组中每个学生的信息");
        Student[] stus=new Student[4];
        for (int i = 0; i < stus.length; i++) {
            stus[i]=new Student();
        }
        stus[0].sno="1";
        stus[0].sname="李勇";
        stus[0].ssex="男";
        stus[0].sage=20;
        stus[0].sdept="CS";
        stus[1].sno="2";
        stus[1].sname="刘晨";
        stus[1].ssex="女";
        stus[1].sage=19;
        stus[1].sdept="CS";
        for (Student stu:stus) {
            System.out.println("sno:"+stu.sno+";sname:"+stu.sname+";ssex:"+stu.ssex+";sage:"+stu.sage+";sdept:"+stu.sdept);
        }

        //3、在测试类中创建课程数组存储课程对象，将数学的学分修改为3，然后打印数组中每门课程的信息。
        System.out.println("------------------------------------------------");
        System.out.println("3、在测试类中创建课程数组存储课程对象，将数学的学分修改为3，然后打印数组中每门课程的信息");
        Course[] courses=new Course[2];
        for (int i = 0; i < courses.length; i++) {
            courses[i]=new Course();
        }
        courses[0].cno="1";
        courses[0].cname="数据库";
        courses[0].cpno="5";
        courses[0].ccredit=4;
        courses[1].cno="2";
        courses[1].cname="数学";
        courses[1].cpno="";
        courses[1].ccredit=2;
        for (Course course:courses) {
            System.out.println("cno:"+course.cno+";cname:"+course.cname+";cpno:"+course.cpno+";ccredit:"+course.ccredit);
        }
        //4、在测试类中创建选修数组存储学生成绩对象，打印数组中每位同学的学号、姓名、课程号、课程名、成绩的信息。
        System.out.println("------------------------------------------------");
        System.out.println("4、在测试类中创建选修数组存储学生成绩对象，打印数组中每位同学的学号、姓名、课程号、课程名、成绩的信息");
        SC[] scs=new SC[2];
        for (int i = 0; i < scs.length; i++) {
            scs[i]=new SC();
        }
        scs[0].sno="1";
        scs[0].cno="1";
        scs[0].grade=92;
        scs[1].sno="2";
        scs[1].cno="2";
        scs[1].grade=90;
        for (SC sc:scs) {
            System.out.println("sno:"+sc.sno+";cno:"+sc.cno+";grade:"+sc.grade);
        }

        for (int i = 0; i < scs.length; i++) {
            String sname="";
            String cname="";
            //找学生姓名
            for (int j = 0; j < stus.length; j++) {
                if(scs[i].sno.equals(stus[j].sno)){
                    sname=stus[j].sname;
                    break;
                }
            }
            //找课程名
            for (int j = 0; j < courses.length; j++) {
                if (scs[i].cno.equals(courses[j].cno)){
                    cname=courses[j].cname;
                    break;
                }
            }
            System.out.println("sno:"+scs[i].sno+";sname:"+sname+";cno:"+scs[i].cno+";cname:"+cname+";grade:"+scs[i].grade);
        }


    }
}
