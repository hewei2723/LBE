package Dao;

import bean.Animal;

public interface AnimalDao {
    //1、声明方法；2、定义一些常量
    public abstract boolean addAnimal(Animal animal);
    public abstract Animal[] getAllAnimal();
}
