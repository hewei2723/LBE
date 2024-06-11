import java.util.Date;
import java.util.Scanner;

public class StudentTest {
    private static StudentManagement studentManagement = new StudentManagement(5);
    private static final String GREEN = "\u001B[32m";
    private static final String BLUE = "\u001B[34m";
    private static final String YELLOW = "\u001B[33m";
    private static final String CYAN = "\u001B[36m";
    private static final String PURPLE = "\u001B[35m";
    public static void main(String[] args) {
        initializeData();
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            printMenu();
            System.out.print("请选择操作：");
            choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    listStudents();
                    break;
                case 2:
                    addStudent(scanner);
                    break;
                case 3:
                    delStudent(scanner);
                    break;
                case 0:
                    System.out.println("程序结束。");
                    break;
                default:
                    System.out.println("选到了隐藏菜单");
                    break;
            }
        } while (choice != 0);
        scanner.close();
    }

    public static void initializeData() {
        studentManagement.addUndergraduate(new Undergraduate("何炜", "B1", "男", new Date(), "计科226", "计科"));
        studentManagement.addUndergraduate(new Undergraduate("何大炜", "B2", "男", new Date(), "计科227", "网管"));
        studentManagement.addGraduate(new Graduate("何二炜", "Y1", "男", new Date(), "计科228", "大何炜", "人工智能"));
        studentManagement.addGraduate(new Graduate("何三炜", "Y2", "男", new Date(), "计科229", "超大何炜", "人工智能"));
    }

    public static void printMenu() {
        System.out.println(GREEN +   "**********꒰˶• ༝ •˶꒱************");
        System.out.println(BLUE +    "****     学生信息管理系统     ****");
        System.out.println(YELLOW +  "****                       ****");
        System.out.println(CYAN +    "****    1. 列出学生 (｡◕‿◕｡)  ****");
        System.out.println(PURPLE +  "****    2. 增加学生 (๑˃ᴗ˂)ﻭ  ****");
        System.out.println(GREEN +   "****    3. 删除学生 (ง'̀-'́)ง  ****");
        System.out.println(BLUE +    "****    0. 退出程序 (^-^*)/  ****");
        System.out.println(YELLOW + "********************************");
        System.out.println(BLUE);
    }

    public static void listStudents() {
        studentManagement.getAllStudentInfo();
    }
    public static void addStudent(Scanner scanner) {
        System.out.print("请输入学生类型（1: 本科生, 2: 研究生）：");
        int type = scanner.nextInt();
        scanner.nextLine();
        if (type == 1) {
            Undergraduate newUndergraduate = new Undergraduate("何本炜", "B3", "男", new Date(), "计科2210", "网络工程");
            studentManagement.addUndergraduate(newUndergraduate);
            System.out.println("已添加本科生: " + newUndergraduate);
        } else if (type == 2) {
            Graduate newGraduate = new Graduate("何研炜", "Y3", "男", new Date(), "计科2211", "超大何炜", "网络工程");
            studentManagement.addGraduate(newGraduate);
            System.out.println("已添加研究生: " + newGraduate);
        }
    }
    public static void delStudent(Scanner scanner) {
        System.out.print("请输入要删除的学生学号：");
        String studentIDToDelete = scanner.nextLine();
        studentManagement.delStudent(studentIDToDelete);
    }
}
