package bean;

public class Bird extends Animal{

    public Bird(){

    }
    public Bird(String name,int age){
        super(name,age);
    }
    public void eat(){
        System.out.println("小鸟吃虫子");
    }

    public void move(){
        System.out.println("小鸟在天上飞");
    }
}
