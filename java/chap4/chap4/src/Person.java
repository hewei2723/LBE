public class Person {
    //char-----'a';String -----"sdfjslkdjf"
    //成员变量和成员方法
    String name;
    int age;
    String gender;
    //String birthday;
    MyDate birthday;

    public void eat(){
        System.out.println("人可以吃饭！！！");
    }

    public void sleep(double hours){
        System.out.println("人一天最少睡"+hours+"小时！！！");
    }

    public void work(){
        System.out.println("人可以工作！！！");
    }

}
