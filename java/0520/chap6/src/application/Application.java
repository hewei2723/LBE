package application;

import DaoImpl.AnimalDaoImpl;
import bean.Animal;
import bean.Bird;
import bean.Fish;

public class Application {
    public static void main(String[] args) {
        //1、接口引用指向接口实现类的实体
       // AnimalDao animalDao=new AnimalDaoImpl();
        //2、直接定义一个实现类的对象
        AnimalDaoImpl ad=new AnimalDaoImpl();
        System.out.println(ad.addAnimal(new Bird("小鸟1",2)));
        System.out.println(ad.addAnimal(new Bird("小鸟2",1)));
        System.out.println(ad.addAnimal(new Fish("小鱼1",3)));
        System.out.println(ad.addAnimal(new Fish("小鱼2",4)));
        //for(数据类型 a:数组名)
        for (Animal animal:ad.getAllAnimal()) {
            System.out.println(animal.getName()+":"+animal.getAge()+"岁");
        }
        System.out.println("-----------------------------");
        //for(int i=0;i<数组名.length;i++)
        Animal[] animals=ad.getAllAnimal();
        for (int i = 0; i <animals.length ; i++) {
            System.out.println(animals[i].getName()+":"+animals[i].getAge()+"岁");
        }
    }
}
