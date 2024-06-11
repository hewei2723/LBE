package src.String;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author lvna
 * @create 2024-05-10 9:23
 * @description 使用正则表达式找出符合规则的字符串
 * 1、制定匹配规则：定义正则表达式变量regex
 * 2、创建匹配模式：Pattern.compile(regex)——为匹配规则创建模式
 * 3、准备待匹配的字符串s
 * 4、创建匹配器match:pattern.matcher(s)——按照匹配模式找s中符合规则的子串放到匹配器中
 * 5、访问匹配器中的子串——找到：matcher.find()、取出：matcher.group()
 *
 * 正则表达式的写法：
 * 由（普通字符、数字、预定义字符类）、逻辑运算符（与、或、非）、量词和边界组成
 */
public class Regex {
    public static void main(String[] args) {
        String regex="\\bdog\\b";
        Pattern pattern= Pattern.compile(regex);
        String s="My dog,your dog,his dog,her dog,we all love it!";
        Matcher matcher=pattern.matcher(s);
        StringBuffer buffer=new StringBuffer();
        while(matcher.find()){
            System.out.println(matcher.group());
            System.out.println("匹配位置在"+matcher.start()+"-"+matcher.end());
            matcher.appendReplacement(buffer,"cat");
        }
        matcher.appendTail(buffer);
        System.out.println(buffer);
        System.out.println(matcher.replaceAll("cat"));
    }
}
