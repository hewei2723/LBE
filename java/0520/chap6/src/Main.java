import bean.Animal;
import bean.Bird;
import bean.Fish;
import shapeAbstract.Circle;
import shapeAbstract.Rectangle;
import shapeAbstract.Shape;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
       //多态性：1、在运用的时候会体现——父类的一个引用指向子类的实体或者是父类自身的一个实体
        //
      /*  Animal animal=new Animal();//父类的引用指向自身的一个实体
        animal.eat();

        animal=new Bird();
        animal.eat();

        animal=new Fish();
        animal.eat();*/
        // 2、抽象类:父类的引用指向子类的实体
        Animal animal=new Bird();
        animal.eat();
        animal.move();

        animal=new Fish();
        animal.eat();
        animal.move();

        Shape shape=new Circle("one",3);
        System.out.println(shape.getName()+"的面积是："+shape.getArea());
        shape=new Rectangle("two",4,5);
        System.out.println(shape.getName()+"的面积是："+shape.getArea());


    }
}