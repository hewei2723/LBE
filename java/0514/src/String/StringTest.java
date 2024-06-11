package src.String;

import java.util.Arrays;

//字符串测试
public class StringTest {
    public static void main(String[] args) {
        String content1 = "Hi";
        content1 = "Hi!";
        String content2 = "Xinxiang Institute of Engineering";
        String content3 = "hi";

        // length
        System.out.println("-------------1、length()-------------");
        System.out.println(content1.length());

        // 根据位置找对应的字符或字符串：charAt、substring
        System.out.println("-------------2、charAt()/substring()-------------");
        System.out.println(content1.charAt(1));
        System.out.println(content2.substring(0, content2.indexOf(" ")));

        // 根据字符串找对应的位置：indexOf、lastIndexOf
        System.out.println("-------------3、indexOf()/lastIndexOf()-------------");
        System.out.println(content1.indexOf("ng"));
        System.out.println(content2.indexOf("ng"));
        System.out.println(content2.indexOf("ng", 10));
        System.out.println(content2.lastIndexOf("ng"));
        System.out.println(content2.lastIndexOf("ng", 11));

        // endsWith、startsWith
        String file = "photo.doc";
        String command = "download photo.png";
        String command2 = "upload photo.png";
        boolean isImage = file.endsWith(".png") || file.endsWith(".jpg");
        System.out.println("-------------4、endsWith()/startWith()-------------");
        if (isImage) {
            System.out.println("这是一个图片文件！");
        } else {
            System.out.println("这不是一个图片文件！");
        }
        if (command.startsWith("download")) {
            System.out.println("这是一个下载命令！");
        } else if (command2.startsWith("upload")) {
            System.out.println("这是一个上传命令！");
        }

        // toLowerCase、toUpperCase
        System.out.println("-------------5、toLowerCase()/toUpperCase()-------------");
        System.out.println(content1.toLowerCase());
        System.out.println(content1.toUpperCase());
        System.out.println(content2.toLowerCase());
        System.out.println(content2.toUpperCase());

        // trim
        System.out.println("-------------6、trim()-------------");
        System.out.println("    " + content2 + "  ");
        System.out.println(("    " + content2 + "  ").trim());

        // concat
        System.out.println("-------------7、concat()-------------");
        System.out.println(content1.concat(",").concat(content2).concat("!"));

        // split
        System.out.println("-------------8、split()-------------");
        String[] words = content2.split(" ");
        System.out.println(Arrays.toString(words));

        // join
        String[] arr = {"a", "b", "c"};
        String str1 = arr[0] + "," + arr[1] + "," + arr[2];
        String str2 = arr[0].concat(",").concat(arr[1]).concat(",").concat(arr[2]);
        String str3 = String.join(",", arr);
        System.out.println("-------------9、join()-------------");
        System.out.println("str1:" + str1);
        System.out.println("str2:" + str2);
        System.out.println("str3:" + str3);

        // equals equalsIgnoreCase
        System.out.println("-------------10、equals()/equalsIgnoreCase()-------------");
        System.out.println(content1.equals(content3));
        System.out.println(content1.equalsIgnoreCase(content3));

        // StringBuffer:支持并发访问，多线程安全
        // StringBuilder：单线程访问
        System.out.println("-------------11、StringBuffer/StringBuilder-------------");
        StringBuffer buffer = new StringBuffer();
        buffer.append(content1);
        System.out.println(buffer);
        buffer.insert(2, ",").insert(3, content2);
        System.out.println(buffer);
        buffer.delete(11, buffer.length());//下标从0开始
        System.out.println(buffer);
        buffer.reverse();
        System.out.println(buffer);

        StringBuilder builder = new StringBuilder();
        builder.append(content1).insert(2, ",").insert(3, content2);
        System.out.println(builder);
    }
}
