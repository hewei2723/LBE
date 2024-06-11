package j240415.extend;

public class ManKind {
    // 成员变量
    protected int sex;
    protected int salary;

    // 构造方法
    public ManKind(int sex, int salary) {
        this.sex = sex;
        this.salary = salary;
    }

    public ManKind() {

    }

    // 根据sex的值显示“man”或“woman”
    public void manOrWoman() {
        if (sex == 1) {
            System.out.println("man");
        } else if (sex == 0) {
            System.out.println("woman");
        } else {
            System.out.println("unknown");
        }
    }

    // 根据salary的值显示“no job”或“job”
    public void employeed() {
        if (salary == 0) {
            System.out.println("no job");
        } else {
            System.out.println("job");
        }
    }
}

