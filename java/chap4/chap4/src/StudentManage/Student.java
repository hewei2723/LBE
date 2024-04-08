package StudentManage;

public class Student {
    String sno;
    private String sname;
    String ssex;
    int sage;
    String sdept;

    public  Student(){

    }
    public Student(String n,  int a){
        sname=n;
        sage=a;

    }
    public Student(String n, int a, String d){
        sname=n;
        sage=a;
        sdept=d;
    }
    public Student(String n, int a, String d,String s){
        sname=n;
        sage=a;
        sdept=d;
        sno=s;

    }
    public Student(String name,String sex,int age){
        sname=sname;
        ssex=sex;
        sage=age;
    }

    public void setSname(String sname) {
        sname = sname;
    }
    public String getSname(){
        return sname;
    }

}
