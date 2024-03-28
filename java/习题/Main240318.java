import java.security.cert.TrustAnchor;
import java.util.Scanner;
public class Main240318 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("************菜单************\n" +
                    "1、计算1累加到1000的结果\n" +
                    "2、打印九九乘法表\n" +
                    "3、输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值\n" +
                    "4、打印水仙花数\n" +
                    "5、小球自由落体之反弹问题\n" +
                    "6、打印菜单\n" +
                    "0、退出程序\n" +
                    "请输入您的选项（0-6范围内的整数）：");

            int num = scanner.nextInt();
            switch (num) {
                case 1:
                    System.out.println("计算1累加到1000的结果");
                    sum();
                    break;
                case 2:
                    System.out.println("打印九九乘法表");
                    nine();
                    break;
                case 3:
                    System.out.println("输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值");
                    zhengshu();
                    break;
                case 4:
                    System.out.println("打印水仙花数");
                    runNarcissisticNumberProgram(scanner);
                    break;
                case 5:
                    System.out.println("小球自由落体之反弹问题");
                    five(scanner);
                    break;
                case 6:
                    System.out.println("打印菜单");
                    printMenu();
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

    public static void sum() {
<<<<<<< HEAD:java/习题/Main240318.java
        int n;
        int sum=0;
        for (n=1;n<=1000;n++) {
            sum+=n;
=======
        int sum = 0;
        for (int n = 1; n <= 1000; n++) {
            sum += n;
>>>>>>> 9eb0cca76bb7cd9b42690029c0f05851340763fc:java/test1/Main240318.java
        }
        System.out.println("1+....+1000=" + sum);
        // 等待用户输入负数来退出
        waitForNegativeInput();
    }

    public static void nine() {
<<<<<<< HEAD:java/习题/Main240318.java
        int m;
        int n;
        int start=0;
        int count=9;
        for(m=start;m<=count;m++){
            for(n=1;n<m+1;n++){
                System.out.print(m+"*"+n+"="+m*n+"    ");
=======
        for (int m = 1; m <= 9; m++) {
            for (int n = 1; n <= m; n++) {
                System.out.print(m + "*" + n + "=" + m * n + "    ");
>>>>>>> 9eb0cca76bb7cd9b42690029c0f05851340763fc:java/test1/Main240318.java
            }
            System.out.println();
        }
        // 等待用户输入负数来退出
        waitForNegativeInput();
    }

    public static int calculateSn(int n) {
        int result = 0;
        int number = 2;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += number;
            number = number * 10 + 2;
        }
        // 等待用户输入负数来退出
        waitForNegativeInput();
        return sum;
    }

    public static void zhengshu() {
        while(true) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("请输入一个正整数 n：");
            int n = scanner.nextInt();
            if (n>0) {
                System.out.println("结果为：" + calculateSns(n));
                waitForNegativeInput();
            }else{
                return;
            }
        }
    }

    public static int calculateSns(int n) {
        int sum = 0;
        int number = 2;

        for (int i = 1; i <= n; i++) {
            sum += number;
            number = number * 10 + 2;
        }
        return sum;
    }

    public static void runNarcissisticNumberProgram(Scanner scanner) {
        int input = 0;
        boolean hasNarcissistic = false;

        while (true) {
            System.out.print("请输入一个数字（输入负数返回菜单）：");
            if (scanner.hasNextInt()) {
                input = scanner.nextInt();
                if (input < 0) {
                    System.out.println("返回菜单。");
                    break; // 返回菜单选项
                }
                hasNarcissistic = printNarcissisticNumbers(input);
                if (!hasNarcissistic) {
                    System.out.println("无水仙花数。");
                }
            } else {
                System.out.println("这是个无效数字，请输入一个有效的数字。");
                scanner.next(); // 清除输入缓冲区
            }
        }
    }

    public static boolean printNarcissisticNumbers(int maxNumber) {
        boolean hasNarcissistic = false;
        for (int i = 100; i <= maxNumber; i++) {
            if (isNarcissistic(i)) {
                System.out.println(i + " 是一个水仙花数。");
                hasNarcissistic = true;
            }
        }
        return hasNarcissistic;
    }

    public static boolean isNarcissistic(int number) {
        int sum = 0;
        int originalNumber = number;
        while (number > 0) {
            int digit = number % 10;
            sum += Math.pow(digit, 3);
            number /= 10;
        }
        return sum == originalNumber;
    }

    public static void five(Scanner scanner) {
        while (true) {
            System.out.print("请输入N的值（输入负数退出）：");
            int n = scanner.nextInt();
            if (n < 0) {
                System.out.println("退出小球自由落体之反弹问题");
                break; // 返回到菜单选项
            }
            double[] result = calculateBounce(n);
            System.out.println("第" + n + "次落地反弹的高度为:" + result[0] + "米");
            System.out.println("总共反弹的距离为：" + result[1] + "米");
        }
    }

    public static double[] calculateBounce(int n) {
        double[] result = new double[2];
        double height = 15.0;
        double totalDistance = 0.0;
        for (int i = 0; i < n; i++) {
            totalDistance += height;
            height /= 2.0;
        }
        result[0] = height;
        result[1] = totalDistance;
        return result;
    }



    public static void printMenu() {
        System.out.print("************菜单************\n" +
                "1、计算1累加到1000的结果\n" +
                "2、打印九九乘法表\n" +
                "3、输入一个正整数n，求Sn=2+22+222+…+22…222（有n个2）之值\n" +
                "4、打印水仙花数\n" +
                "5、小球自由落体之反弹问题\n" +
                "6、打印菜单\n" +
                "0、退出程序\n");
    }


    public static void waitForNegativeInput() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("请输入负数返回菜单：");
            int input = scanner.nextInt();
            if (input < 0) {
                break;
            }
        }
    }
}

