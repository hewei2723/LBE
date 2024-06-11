import java.util.Scanner;

public class one {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入圆的半径: ");
        double radius = scanner.nextDouble();
        Circle.calculate(radius);

        System.out.print("请输入矩形的长: ");
        double length = scanner.nextDouble();
        System.out.print("请输入矩形的宽: ");
        double width = scanner.nextDouble();
        Rectangle.calculate(length, width);
    }
}

class Circle {
    public static void calculate(double radius) {
        double circumference = 2 * Math.PI * radius;
        double area = Math.PI * radius * radius;

        System.out.println("半径为: " + radius + " 的圆");
        System.out.println("周长: " + circumference);
        System.out.println("面积: " + area);
    }
}

class Rectangle {
    public static void calculate(double length, double width) {
        double perimeter = 2 * (length + width);
        double area = length * width;

        System.out.println("长为: " + length + " 宽为: " + width + " 的矩形");
        System.out.println("周长: " + perimeter);
        System.out.println("面积: " + area);
    }
}