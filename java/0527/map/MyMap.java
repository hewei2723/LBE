package map;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MyMap {
    public static void main(String[] args) {

      /* ** 添加 **
            - Object put(Object key,Object value)：将指定key-value添加到(或修改)当前map对象中
            - void putAll(Map m):将m中的所有key-value对存放到当前map中
         ** 删除操作 **
            - Object remove(Object key)：移除指定key的key-value对，并返回value
            - void clear()：清空当前map中的所有数据
        ** 修改 **  同添加
        ** 查询 **
           - Object get(Object key)：获取指定key对应的value
           - boolean containsKey(Object key)：是否包含指定的key
           - boolean containsValue(Object value)：是否包含指定的value
           - boolean isEmpty()：判断当前map是否为空
        ** 长度 **
           - int size()：返回map中key-value对的个数
        ** 遍历 **
           - Set keySet()：返回所有key构成的Set集合
           - Collection values()：返回所有value构成的Collection集合
           - Set entrySet()：返回所有key-value对构成的Set集合
*/

        //学生信息
        //001 张三
        //002 李四
        //003 王五
        Map<String,Student> studentScores = new HashMap<String, Student>();

        //添加元素 - Object put(Object key,Object value)
        System.out.println("——————添加元素——————");
        studentScores.put("001", new Student("001", "张三"));
        studentScores.put("002", new Student("002", "李四"));
        studentScores.put("003", new Student("003", "王五"));
        System.out.println("长度："+studentScores.size()+","+studentScores);

        //删除元素 - Object remove(Object key)
        System.out.println("——————删除元素——————");
        studentScores.remove("003");
        System.out.println("长度："+studentScores.size()+","+studentScores);

        //修改元素 - Object put(Object key,Object value)
        System.out.println("——————修改元素——————");
        studentScores.put("003", new Student("003", "赵六"));
        System.out.println("长度："+studentScores.size()+","+studentScores);
        studentScores.put("003", new Student("003", "王五"));
        System.out.println("长度："+studentScores.size()+","+studentScores);

        //查询元素
        //1、- Object get(Object key)
        System.out.println("——————根据键查询值——————");
        Student s1=studentScores.get("004");
        if(s1!=null){
            System.out.println("key=001 value="+s1.sno+","+s1.name);
        }
        //2、- boolean containsKey(Object key)
        System.out.println("——————查询键是否存在——————");
        if(studentScores.containsKey("001")){
            System.out.println("map的key值有001");
        }else{
            System.out.println("map的key值没有001");
        }
        if(studentScores.containsKey("004")){
            System.out.println("map的key值有004");
        }else{
            System.out.println("map的key值没有004");
        }
        //3、- boolean containsValue(Object value)
        System.out.println("——————查询值是否存在——————");
        if(studentScores.containsValue(new Student("001", "张三"))){
            System.out.println("集合中有001,张三");
        }else{
            System.out.println("集合中没有001,张三");
        }
        //4、boolean isEmpty()
        System.out.println("——————判断map集合是否为空——————");
        System.out.println("map是否为空："+studentScores.isEmpty());

        //遍历
        //1、- Set keySet()
        System.out.println("——————遍历键——————");
        Set<String> keys=studentScores.keySet();
        for(String key:keys){
            System.out.println("key="+key);
        }
        //2、- Collection values()
        System.out.println("——————遍历值——————");
        Collection<Student> values=studentScores.values();
        for(Student s:values){
            System.out.println("sno="+s.sno+",sname="+s.name);
        }
        //3、- Set<Map.Entry<K,V>> entrySet()
        System.out.println("——————遍历键值对——————");
        Set<Map.Entry<String,Student>> entries=studentScores.entrySet();
        for(Map.Entry<String,Student> entry:entries){
            String key=entry.getKey();
            Student value=entry.getValue();
            System.out.println("key="+key+",value="+value.sno+","+value.name);
        }
    }
}
