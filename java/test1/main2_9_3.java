import java.util.Scanner;
public class main2_9_3 {
    public static void main(String[] args) {
        System.out.print("请输入原码：");
        Scanner scn=new Scanner(System.in);
        int o=scn.nextInt();
        if (o>=1000&&o<10000){
        int a = (o / 1000 + 5) % 10;
        int b = ((o % 1000) / 100 + 5) % 10;
        int c = ((o % 100) / 10 + 5) % 10;
        int d = (o % 10 + 5) % 10;
        int e = a* 1000 + b * 100 + c * 10 + d;
        System.out.println("加密后为: " + e);
    }
        else
    {
        System.out.println("请输入四位整数！");
        }
    }
}