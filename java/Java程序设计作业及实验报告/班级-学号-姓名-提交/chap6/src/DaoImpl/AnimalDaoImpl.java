package DaoImpl;

import Dao.AnimalDao;
import bean.Animal;

public class AnimalDaoImpl implements AnimalDao {
    private Animal[] animals=new Animal[3];
    private  int count=0;//用来记录当前动物园已经有了多少个动物。count<=animals的长度

    //购买动物
    @Override
    public boolean addAnimal(Animal animal) {
        if(count< animals.length){
            animals[count]=animal;
            count++;
            return true;
        }else{
            return false;
        }

    }
    //查看动物园中有哪些动物
    @Override
    public Animal[] getAllAnimal() {
        return animals;
    }
}
