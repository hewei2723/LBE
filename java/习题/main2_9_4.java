import java.util.Scanner;
public class main2_9_4 {
    public static void main(String[]args){
        System.out.print("请输入一个数字：");
        Scanner scn=new Scanner(System.in);
        int num=scn.nextInt();
        String two=Integer.toBinaryString(num);
        System.out.println("二进制为："+two);
    }
}
