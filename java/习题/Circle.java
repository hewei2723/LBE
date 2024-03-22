import java.util.Scanner;
//定义一个Circle类
public class Circle {
    //定义一个计算圆面积的方法
    public static double calculateCircleArea(double radius) {
        return Math.PI * Math.pow(radius, 2);
    }
    public static void main(String[] args) {
        //创建一个Scanner对象
        try (Scanner scanner = new Scanner(System.in)) {
            //提示用户输入圆的半径
            System.out.print("输入圆的半径 ");
            double radius = scanner.nextDouble();

            //调用calculateCircleArea方法计算圆的面积
            double area = calculateCircleArea(radius);
            //输出圆的面积
            System.out.println("圆的面积是: " + area);
        } catch (Exception e) {
            //捕获异常，如果输入的不是数字，则提示用户输入有效的半径
            System.out.println("Invalid input. Please enter a valid number for the radius.");
        }
        //关闭Scanner对象
    }
}
