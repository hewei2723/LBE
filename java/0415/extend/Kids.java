package j240415.extend;

public class Kids extends j240415.extend.ManKind {
    // 成员变量
    private final int yearsOld;

    // 构造方法
    public Kids(int sex, int salary, int yearsOld) {
        super(); // 调用父类的构造方法初始化父类的属性
        this.yearsOld = yearsOld;
    }

    // 打印yearsOld的值
    public void printAge() {
        System.out.println("Years Old: " + yearsOld);
    }

    public void manOrWoman() {
    }
}
