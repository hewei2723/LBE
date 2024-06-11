package bean;

import Dao.AnimalDao;

public abstract class Animal  {
    //1、属性；2、构造器（构造方法）；3、方法（一个类可以做什么事）
    //private修饰的方法、属性的作用域只限于当前类，所以需要使用get、set
    //抽象类与抽象方法：
    //1、都是使用abstract来表示抽象：抽象类——abstract class；抽象方法是在数据类型前加abstract——public abstract void eat();
    //2、抽象方法是必须放在抽象类中的
    //3、抽象类中既可以有抽象方法，也可以有非抽象方法
    //4、抽象方法必须在子类中去实现。如果子类不实现，那么子类必须也是抽象类
    //5、抽象方法的访问权限修饰符设置为public
    private String name;
    private int age;

    public Animal(){
        System.out.println("欢迎来到动物世界！");
    }

    public Animal(String name,int age){
        this.name=name;
        this.age=age;
    }

    public abstract void eat();

    public abstract void move();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
