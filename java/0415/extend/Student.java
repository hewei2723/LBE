package j240415.extend;

public class Student extends Person {
    // 子类新增属性
    private long studentNumber;
    private int math;
    private int english;
    private int computer;

    // 子类构造方法
    public Student(String name, char sex, int age, long studentNumber, int math, int english, int computer) {
        super(name, sex, age); // 调用父类的构造方法来初始化父类的属性
        this.studentNumber = studentNumber;
        this.math = math;
        this.english = english;
        this.computer = computer;
    }

    // 计算平均分的方法
    public double average() {
        return (math + english + computer) / 3.0;
    }

    // 计算最高分的方法
    public int max() {
        return Math.max(math, Math.max(english, computer));
    }

    // 计算最低分的方法
    public int min() {
        return Math.min(math, Math.min(english, computer));
    }

    @Override
    public String toString() {
        return super.toString() + ", StudentNumber: " + studentNumber +
                ", Math: " + math + ", English: " + english + ", Computer: " + computer;
    }

    public static void main(String[] args) {
        // 创建一个学生对象并打印信息
        Student student = new Student("Alice", 'F', 18, 1234567890, 90, 85, 95);
        System.out.println(student.toString());
        System.out.println("Average score: " + student.average());
        System.out.println("Max score: " + student.max());
        System.out.println("Min score: " + student.min());
    }
}
