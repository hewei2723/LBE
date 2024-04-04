import java.util.Scanner;

public class duix2 {
    public static int add(int x1, int x2){
        return x1+x2;
    }
    public static void main(String[]args){
        int a,b;
        Scanner sc=new Scanner(System.in);
        System.out.print("请输入一个数：");
        a=sc.nextInt();
        System.out.print("请输入第二个数：");
        b=sc.nextInt();
        System.out.print("结果：");
        System.out.println(add(a,b));
    }
}
