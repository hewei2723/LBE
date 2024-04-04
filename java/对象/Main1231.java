import java.util.Scanner;

public class Main1231 {
    public static void main(String[] args) {
        Scanner a=new Scanner(System.in);
        System.out.println("请输入一个整数");
        int x1=a.nextInt();
        Scanner b=new Scanner(System.in);
        System.out.println("请输入一个整数");
        int x2=b.nextInt();
        int x3=x1+x2;
        System.out.println(x3);
    }
}