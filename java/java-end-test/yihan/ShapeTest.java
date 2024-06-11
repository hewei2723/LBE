import java.util.Scanner;

public class ShapeTest {
    private static Area[] rectangles = new Area[5];
    private static CircleArea[] circles = new CircleArea[5];
    private static int rcount = 0;
    private static int ccount = 0;
    public static void main(String[] args) {
        initializeData();
        Scanner scanner = new Scanner(System.in);
        int menu;
        do {
            printMenu();
            System.out.print("请选择一个选项：");
            menu = scanner.nextInt();
            scanner.nextLine();
            switch (menu) {
                case 1:
                    addRectangle();
                    break;
                case 2:
                    addCircle();
                    break;
                case 3:
                    remove(scanner);
                    break;
                case 4:
                    search(scanner);
                    break;
                case 5:
                    calcArea();
                    break;
                case 6:
                    System.out.println("程序结束。");
                    break;
                default:
                    System.out.println("无效的选项，请重试。");
                    break;
            }
            listAllShapes();
        } while (menu != 6);

        scanner.close();
    }

    private static void initializeData() {
        // 初始化一些预定义的图形数据
        rectangles[0] = new Area("Rectangle1", "R1", "Red", 2, 4, 2);
        rectangles[1] = new Area("Rectangle2", "R2", "Green", 3, 5, 3);
        circles[0] = new CircleArea("Circle1", "C1", "Blue", 1, 3);
        circles[1] = new CircleArea("Circle2", "C2", "Yellow", 1.5, 4);
        rcount = 2;
        ccount = 2;
    }

    private static void printMenu() {
        System.out.println("1. 添加矩形");
        System.out.println("2. 添加圆形");
        System.out.println("3. 删除图形");
        System.out.println("4. 查询图形信息");
        System.out.println("5. 计算图形面积");
        System.out.println("6. 退出");
    }

    private static void addRectangle() {
        if (rcount >= rectangles.length) {
            System.out.println("矩形数组已满，无法添加新矩形。");
            return;
        }
        rectangles[rcount++] = new Area("Rectangle" + (rcount + 1), "R" + (rcount + 1), "Color" + (rcount + 1), 2, 4, 2);
        System.out.println("矩形添加成功！");
    }

    private static void addCircle() {
        if (ccount >= circles.length) {
            System.out.println("圆形数组已满，无法添加新圆形。");
            return;
        }
        circles[ccount++] = new CircleArea("Circle" + (ccount + 1), "C" + (ccount + 1), "Color" + (ccount + 1), 1, 3);
        System.out.println("圆形添加成功！");
    }

    private static void remove(Scanner scanner) {
        System.out.print("输入要删除的图形编号：");
        String id = scanner.nextLine();
        for (int i = 0; i < rcount; i++) {
            if (rectangles[i].getShapeID().equals(id)) {
                rectangles[i] = rectangles[--rcount]; // 计数减少
                rectangles[rcount] = null;
                System.out.println("矩形删除成功！");
                return;
            }
        }
        for (int i = 0; i < ccount; i++) {
            if (circles[i].getShapeID().equals(id)) {
                circles[i] = circles[--ccount]; // 计数器减少
                circles[ccount] = null;
                System.out.println("圆形删除成功！");
                return;
            }
        }
        System.out.println("这个编号没有图形哦。");
    }

    private static void search(Scanner scanner) {
        System.out.print("输入要查询的图形编号：");
        String id = scanner.nextLine();
        for (int i = 0; i < rcount; i++) {
            if (rectangles[i].getShapeID().equals(id)) {
                System.out.println(rectangles[i]);
                return;
            }
        }
        for (int i = 0; i < ccount; i++) {
            if (circles[i].getShapeID().equals(id)) {
                System.out.println(circles[i]);
                return;
            }
        }
        System.out.println("这个编号没有图形哦。");
    }

    private static void calcArea() {
        System.out.println("矩形的面积：");
        for (int i = 0; i < rcount; i++) {
            System.out.println("长方形编号: " + rectangles[i].getShapeID() + ", 面积: " + rectangles[i].calculateArea());
        }
        System.out.println("圆形的面积：");
        for (int i = 0; i < ccount; i++) {
            System.out.println("圆形编号: " + circles[i].getShapeID() + ", 面积: " + circles[i].calculateArea());
        }
    }

    private static void listAllShapes() {
        System.out.println("\n当前所有图形：");
        System.out.println("矩形：");
        for (int i = 0; i < rcount; i++) {
            System.out.println(rectangles[i]);
        }
        System.out.println("圆形：");
        for (int i = 0; i < ccount; i++) {
            System.out.println(circles[i]);
        }
    }
}
