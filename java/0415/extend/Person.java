package j240415.extend;

public class Person {
    public String name;
    public char sex;
    public int age;

    public Person(String name, char sex, int age) {
        this.name = name;
        this.sex = sex;
        this.age = age;
    }

    public String toString() {
        return "名字：" + name + "性别" + sex + "年龄" + age;
    }
}

