//（6）主控类设计（执行main方法的类）（10分）
//        创建一个ShapeTest类，在该类中创建
//        一个矩形数组 菜单1
//        一个圆数组 菜单2
//        每个数组的长度为5。
//        分别对每个数组实现
//        删除图形 菜单3
//        通过图形编号查询图形 菜单4
//        计算面积操作 菜单5（10分）

import java.util.Scanner;
public class ShapeTest {
    private static Area[] rectangles = new Area[5];
    private static CircleArea[] circles = new CircleArea[5];
    private static int rectanglecount = 0;
    private static int circlecount = 0;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // 先看看能不能跑
        rectangles[0] = new Area("Rectangle1", "R1", "Red", 2.0, 5.0, 3.0);
        rectanglecount = 1;
        circles[0] = new CircleArea("Circle1", "C1", "Red", 2.0, 3.0);
        circlecount = 1;
        int choice;
        do {
            System.out.println("\n图形管理系统菜单：");
            System.out.println("1. 添加矩形");
            System.out.println("2. 添加圆形");
            System.out.println("3. 删除图形");
            System.out.println("4. 查询图形信息");
            System.out.println("5. 计算图形面积");
            System.out.println("6. 退出");
            System.out.print("请选择一个选项：");
            choice = scanner.nextInt();
            scanner.nextLine(); // 消耗换行符
            switch (choice) {
                case 1:
                    addrectangle(scanner);
                    break;
                case 2:
                    addcircle(scanner);
                    break;
                case 3:
                    deleteshape(scanner);
                    break;
                case 4:
                    search(scanner);
                    break;
                case 5:
                    calcArea();
                    break;
                case 6:
                    break;
                default:
                    System.out.println("无效的选项，请重试。");
            }
        }while (choice!=6);
    }
    private static void addrectangle(Scanner scanner) {
        if (rectanglecount >= rectangles.length) {
            System.out.println("矩形数组已满，无法添加新矩形。");
            return;
        }
        System.out.print("输入矩形名称：");
        String name = scanner.nextLine();
        System.out.print("输入矩形编号(R开头+数字)：");
        String id = scanner.nextLine();
        System.out.print("输入颜色：");
        String color = scanner.nextLine();
        System.out.print("输入边框宽度：");
        double borderWidth = scanner.nextDouble();
        System.out.print("输入长度：");
        double length = scanner.nextDouble();
        System.out.print("输入宽度：");
        double width = scanner.nextDouble();
        scanner.nextLine();
        rectangles[rectanglecount++] = new Area(name, id, color, borderWidth, length, width);
        System.out.println("矩形添加成功！");
    }
    private static void addcircle(Scanner scanner) {
        if (circlecount >= circles.length) {
            System.out.println("圆形数组已满，无法添加新圆形。");
            return;
        }
        System.out.print("输入圆形名称：");
        String name = scanner.nextLine();
        System.out.print("输入圆形编号(C开头+数字)：");
        String id = scanner.nextLine();
        System.out.print("输入颜色：");
        String color = scanner.nextLine();
        System.out.print("输入边框宽度：");
        double borderWidth = scanner.nextDouble();
        System.out.print("输入半径：");
        double radius = scanner.nextDouble();
        scanner.nextLine();
        circles[circlecount++] = new CircleArea(name, id, color, borderWidth, radius);
        System.out.println("圆形添加成功！");
    }
    private static void deleteshape(Scanner scanner) {
        System.out.print("输入要删除的图形编号：");
        String id = scanner.nextLine();
        for (int i = 0; i < rectanglecount; i++) {
            if (rectangles[i].getShapeID().equals(id)) {
                rectangles[i] = rectangles[--rectanglecount];//计数减少，
                rectangles[rectanglecount] = null;
                System.out.println("矩形删除成功！");
                return;
            }
        }
        for (int i = 0; i < circlecount; i++) {
            if (circles[i].getShapeID().equals(id)) {
                circles[i] = circles[--circlecount];//计数器减少
                circles[circlecount] = null;
                System.out.println("圆形删除成功！");
                return;
            }
        }
        System.out.println("这个编号没有图形哦。");
    }
    private static void search(Scanner scanner) {
        System.out.print("输入要查询的图形编号：");
        String id = scanner.nextLine();
        for (int i = 0; i < rectanglecount; i++) {
            if (rectangles[i].getShapeID().equals(id)) {
                System.out.println(rectangles[i]);
                return;
            }
        }
        for (int i = 0; i < circlecount; i++) {
            if (circles[i].getShapeID().equals(id)) {
                System.out.println(circles[i]);
                return;
            }
        }
        System.out.println("这个编号没有图形哦。");
    }
    private static void calcArea() {
        System.out.println("矩形的面积：");
        for (int i = 0; i < rectanglecount; i++) {
            System.out.println("Rectangle ID: " + rectangles[i].getShapeID() + ", Area: " + rectangles[i].calculateArea());
        }
        System.out.println("圆形的面积：");
        for (int i = 0; i < circlecount; i++) {
            System.out.println("Circle ID: " + circles[i].getShapeID() + ", Area: " + circles[i].calculateArea());
        }
    }
}