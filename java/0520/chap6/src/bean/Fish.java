package bean;

public class Fish extends bean.Animal {
    //方法的重写：子类对从父类中继承过来的方法重新进行改造

    public Fish(){

    }
    public Fish(String name,int age){
        super();
    }
    public void eat(){
        System.out.println("大鱼吃小鱼，小鱼吃虾米");
    }

    public void move(){
        System.out.println("鱼在水中游");
    }
}
