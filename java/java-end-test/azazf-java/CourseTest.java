import java.util.Scanner;

public class CourseTest {
    private static RequiredCourse[] requiredCourses = new RequiredCourse[5];
    private static ElectiveCourse[] electiveCourses = new ElectiveCourse[5];
    private static Scanner scanner = new Scanner(System.in);
    private static String[] chioceCourses = new String[10];
    private static int enrolledCount = 0;

    static {
        // 初始化必修课数组
        requiredCourses[0] = new RequiredCourse("数学", "1", "张老师", 3, "周一 10:00-12:00", "笔试");
        requiredCourses[1] = new RequiredCourse("英语", "2", "李老师", 2, "周二 14:00-16:00", "笔试");
        requiredCourses[2] = new RequiredCourse("计算机", "3", "王老师", 4, "周三 08:00-10:00", "上机考试");
        requiredCourses[3] = new RequiredCourse("物理", "4", "赵老师", 3, "周四 10:00-12:00", "笔试");


        // 初始化选修课数组
        electiveCourses[0] = new ElectiveCourse("艺术", "1", "钱老师", 2, "周一 14:00-16:00", "无");
        electiveCourses[1] = new ElectiveCourse("心理学", "2", "吴老师", 3, "周二 10:00-12:00", "无");
        electiveCourses[2] = new ElectiveCourse("编程", "3", "郑老师", 4, "周三 14:00-16:00", "计算机");
        electiveCourses[3] = new ElectiveCourse("经济学", "4", "周老师", 3, "周四 08:00-10:00", "数学");

    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("--------欢迎使用课程管理系统--------");
            System.out.println("请选择操作：");
            System.out.println("1. 添加课程");
            System.out.println("2. 删除课程");
            System.out.println("3. 查询课程");
            System.out.println("4. 选课");
            System.out.println("5. 退出");
            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    addCourse();
                    break;
                case 2:
                    deleteCourse();
                    break;
                case 3:
                    searchCourse();
                    break;
                case 4:
                    enrollCourse();
                    break;
                case 5:
                    System.out.println("退出系统");
                    return;
                default:
                    System.out.println("无效选择，请重新选择");
            }
        }
    }

    private static void addCourse() {
        while (true) {
            System.out.println("选择课程类型：1. 必修课 2. 选修课 0. 返回菜单");
            int type = scanner.nextInt();
            scanner.nextLine();

            if (type == 0) return;

            System.out.print("输入课程名称：");
            String courseName = scanner.nextLine();
            System.out.print("输入课程编号：");
            String courseID = scanner.nextLine();
            System.out.print("输入授课教师：");
            String instructor = scanner.nextLine();
            System.out.print("输入学分：");
            int credits = scanner.nextInt();
            scanner.nextLine();
            System.out.print("输入上课时间：");
            String schedule = scanner.nextLine();

            if (type == 1) {
                System.out.print("输入考试形式：");
                String examType = scanner.nextLine();
                for (int i = 0; i < requiredCourses.length; i++) {
                    if (requiredCourses[i] != null && requiredCourses[i].getCourseName().equals(courseName)) {
                        System.out.println("已有该课程");
                        return;
                    }
                    if (requiredCourses[i] == null) {
                        requiredCourses[i] = new RequiredCourse(courseName, courseID, instructor, credits, schedule, examType);
                        System.out.println("必修课添加成功");
                        printCourses();
                        return;
                    }
                }
                System.out.println("课程已满");
            } else if (type == 2) {
                System.out.print("输入先修课程：");
                String prerequisite = scanner.nextLine();
                for (int i = 0; i < electiveCourses.length; i++) {
                    if (electiveCourses[i] != null && electiveCourses[i].getCourseName().equals(courseName)) {
                        System.out.println("已有该课程");
                        return;
                    }
                    if (electiveCourses[i] == null) {
                        electiveCourses[i] = new ElectiveCourse(courseName, courseID, instructor, credits, schedule, prerequisite);
                        System.out.println("选修课添加成功");
                        printCourses();
                        return;
                    }
                }
                System.out.println("课程已满");
            } else {
                System.out.println("无效的课程类型");
            }
        }
    }

    private static void deleteCourse() {
        while (true) {
            System.out.println("选择课程类型：1. 必修课 2. 选修课 0. 返回菜单");
            int type = scanner.nextInt();
            scanner.nextLine();

            if (type == 0) return;

            System.out.print("输入课程编号：");
            String courseID = scanner.nextLine();

            if (type == 1) {
                for (int i = 0; i < requiredCourses.length; i++) {
                    if (requiredCourses[i] != null && requiredCourses[i].getCourseID().equals(courseID)) {
                        requiredCourses[i] = null;
                        System.out.println("必修课删除成功");
                        printCourses();
                        return;
                    }
                }
            } else if (type == 2) {
                for (int i = 0; i < electiveCourses.length; i++) {
                    if (electiveCourses[i] != null && electiveCourses[i].getCourseID().equals(courseID)) {
                        electiveCourses[i] = null;
                        System.out.println("选修课删除成功");
                        printCourses();
                        return;
                    }
                }
            } else {
                System.out.println("无效的课程类型");
            }
        }
    }

    private static void searchCourse() {
        while (true) {
            System.out.println("选择课程类型：1. 必修课 2. 选修课 0. 返回菜单");
            int type = scanner.nextInt();
            scanner.nextLine();

            if (type == 0) return;

            System.out.print("输入课程编号：");
            String courseID = scanner.nextLine();

            if (type == 1) {
                for (Course course : requiredCourses) {
                    if (course != null && course.getCourseID().equals(courseID)) {
                        System.out.println(course);
                        return;
                    }
                }
            } else if (type == 2) {
                for (Course course : electiveCourses) {
                    if (course != null && course.getCourseID().equals(courseID)) {
                        System.out.println(course);
                        return;
                    }
                }
            } else {
                System.out.println("无效的课程类型");
            }
            System.out.println("课程不存在");
        }
    }

    private static void enrollCourse() {
        while (true) {
            System.out.println("选择课程类型：1. 必修课 2. 选修课 0. 返回菜单");
            int type = scanner.nextInt();
            scanner.nextLine();

            if (type == 0) return;

            System.out.print("输入课程编号：");
            String courseID = scanner.nextLine();

            // 检查是否已选过该课程
            for (String enrolledCourse : chioceCourses) {
                if (courseID.equals(enrolledCourse)) {
                    System.out.println("选课重复");
                    return;
                }
            }

            if (type == 1) {
                for (RequiredCourse course : requiredCourses) {
                    if (course != null && course.getCourseID().equals(courseID)) {
                        chioceCourses[enrolledCount++] = courseID;
                        CourseManagement requiredCourseManagement = new RequiredCourseManagement();
                        requiredCourseManagement.enroll();
                        return;
                    }
                }
            } else if (type == 2) {
                for (ElectiveCourse course : electiveCourses) {
                    if (course != null && course.getCourseID().equals(courseID)) {
                        System.out.print("是否完成选修课程（true/false）：");
                        boolean prerequisiteCompleted = scanner.nextBoolean();
                        chioceCourses[enrolledCount++] = courseID;
                        CourseManagement electiveCourseManagement = new ElectiveCourseManagement(course, prerequisiteCompleted);
                        electiveCourseManagement.enroll();
                        return;
                    }
                }
            } else {
                System.out.println("无效的课程类型");
            }
            System.out.println("课程不存在");
        }
    }

    private static void printCourses() {
        System.out.println("必修课列表：");
        for (RequiredCourse course : requiredCourses) {
            if (course != null) {
                System.out.println(course);
            }
        }

        System.out.println("选修课列表：");
        for (ElectiveCourse course : electiveCourses) {
            if (course != null) {
                System.out.println(course);
            }
        }
    }
}
