import java.util.Scanner;
public class Main240318 {
    public static void main(String []args){
        System.out.print("************菜单************\n" +
                "1、计算1累加到1000的结果\n" +
                "2、打印九九乘法表\n" +
                "3、输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值\n" +
                "4、打印水仙花数\n" +
                "5、小球自由落体之反弹问题\n" +
                "6、显示菜单选项\n" +
                "0、退出程序\n" +
                "请输入您的选项（0-6范围内的整数）：");
        while (true){
            Scanner scanner = new Scanner(System.in);
            int num;
            num = scanner.nextInt();
            switch (num) {
                case 1:
                    System.out.println("计算1累加到1000的结果");
                    sum();
                    System.out.print("请继续（按6显示菜单）：");
                    break;
                case 2:
                    System.out.println("打印九九乘法表");
                    nine();
                    System.out.print("请继续（按6显示菜单）：");
                    break;
                case 3:
                    System.out.println("输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值");
                    System.out.print("请继续（按6显示菜单）：");
                    break;
                case 4:
                    System.out.println("打印水仙花数");
                    water();
                    System.out.print("请继续（按6显示菜单）：");
                    break;
                case 5:
                    System.out.println("小球自由落体之反弹问题");
                    five();
                    System.out.print("请继续（按6显示菜单）：");
                    break;
                case 6:
                    System.out.println("显示菜单选项");
                    System.out.print("************菜单************\n" +
                            "1、计算1累加到1000的结果\n" +
                            "2、打印九九乘法表\n" +
                            "3、输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值\n" +
                            "4、打印水仙花数\n" +
                            "5、小球自由落体之反弹问题\n" +
                            "6、显示菜单选项\n" +
                            "0、退出程序\n" +
                            "请输入您的选项（0-6范围内的整数）：");
                    break;
                case 0:
                    System.out.println("退出程序");
                    scanner.close();
                    return;
                default:
                    System.out.println("请输入正确的序号");
            }
        }
    }
    public static void sum() {;
        int n=1;
        int sum=0;
        for (n=1;n<=1000;n++) {
            sum+=n;
        }
        System.out.println("1+....+1000="+sum);
    }
    public static void nine() {;
        int m;
        int n;
        int start=0;
        int count=9;
        for(m=start;m<=count;m++){
            for(n=1;n<m+1;n++){
                System.out.print(m+"*"+n+"="+m*n+"    ");
            }
            System.out.println();
        }

    }
    public static void five() {
        Scanner scanner = new Scanner(System.in);
        int n;
        while (true) {
            System.out.print("请输入N的值（输入负数退出）：");
            n = scanner.nextInt();
            if (n < 0) {
                System.out.println("程序退出");
                break;
            }
            double[] result = calcylateBounce(n);
            System.out.println("第" + n + "次落地反弹的高度为:"+result[0] + "米");
            System.out.println("总共反弹的距离为：" + result[1] + "米");
        }
    }
    public static double[] calcylateBounce(int n) {
        double[] result = new double[2];
        double height = 15.0;
        double totalDistance = 0.0;

        for (int i = 0; i < n; i++) {
            totalDistance+=height;
            height/=2.0;

        }
        result[0]=height;
        result[1]=totalDistance;
        return result;
    }
    public static void water() {
        Scanner scanner=new Scanner(System.in);
        int number=scanner.nextInt();
        int g = number % 10;
        int s = (number / 10) % 10;
        int b = number / 100;
        int sum = (g * g * g) + (s * s * s) + (b + b + b);
        if (sum==number){
            System.out.println("是一个水仙花数");
        }
        else{
            System.out.println("不是一个水仙花数");
        }
    }
}
