package list;

import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;

/**
 * @author lvna
 * @create 2024-05-19 17:55
 * @description
 */
public class MyList {
    public static void main(String[] args) {
        //用List存储数据[1,5.2,'a',false,"s","s"]

        //添加元素
        List list=new ArrayList();
        List list2=new LinkedList();
        list.add(1);
        list.add(5.2);
        list.add('a');
        list.add(false);
        list.add("s");
        list.add("s");

        list2.add(1);
        list2.add(5.2);
        list2.add('a');
        list2.add(false);
        list2.add("s");

        //查询元素
        //1、根据索引位置找元素
        System.out.println("1、根据索引位置找元素");
        for (Object o:list) {
            System.out.println(o);
        }
        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }
        for(int i=0;i<list2.size();i++){
            System.out.println(list2.get(i));
        }
        //2、根据元素找索引位置
        System.out.println("2、根据元素找索引位置");
        System.out.println("查询字符a的位置："+list.indexOf('a'));
        System.out.println("查询字符串a的位置："+list.indexOf("a"));

        System.out.println("查询字符a的位置："+list2.indexOf('a'));
        System.out.println("查询字符串a的位置："+list2.indexOf("a"));

        //修改元素
        System.out.println("3、修改元素");
        System.out.println("被修改的元素是："+list.set(1,100));
        System.out.println("修改后的元素是："+list.get(1));

        System.out.println("被修改的元素是："+list2.set(1,100));
        System.out.println("修改后的元素是："+list2.get(1));

        //删除元素
        System.out.println("4、删除元素[1,100,'a',false,\"s\",\"s\"]");
        list.remove(1);//尝试删除其他元素
       // list.removeAll(list);
      //  list2.removeAll(list2);
        System.out.println("删除元素后list的大小为："+list.size());
        for(int i=0;i<list.size();i++){
            System.out.println(list.get(i));
        }

        System.out.println("删除元素后list2的大小为："+list2.size());

    }
}
