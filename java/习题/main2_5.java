package 习题;
import java.util.Scanner;

public class main2_5 {
    public static void main(String[] args){
        byte plane=90;
        System.out.print("输入要查询的航班：");
        @SuppressWarnings("resource")
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        if((plane&(1<<n))>0){
            System.out.println("该日有航班");
        }
        else{
            System.out.println("该日无航班");
        }

    }
}
