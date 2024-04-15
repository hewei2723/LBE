package 面向对象编程.own;

import 面向对象编程.own.Person;

public class PersonTest {

    public static void main(String[] args) {
        Person p1=new Person();
        p1.name="金冉冉";
        p1.age=20;
        p1.gender="女";
        System.out.println("姓名："+p1.name+";age:"+p1.age+";gender"+p1.gender+"birth:"+p1.birthday);
    }
}
