package StudentManage;

public class StudentTest {
    public static void main(String[] args) {
        Student s1=new Student("jack",20);
        Student s2=new Student("jack",20,"CS");
        Student s3=new Student("jack",20,"CS","2022110302");

        System.out.println("s1信息："+s1.getSname()+"\t"+s1.sage+"\t"+s1.sdept+"\t"+s1.sno+"\t"+s1.ssex);
        System.out.println("s2信息："+s2.getSname()+"\t"+s2.sage+"\t"+s2.sdept+"\t"+s2.sno+"\t"+s2.ssex);
        System.out.println("s3信息："+s3.getSname()+"\t"+s3.sage+"\t"+s3.sdept+"\t"+s3.sno+"\t"+s3.ssex);
    }
}
