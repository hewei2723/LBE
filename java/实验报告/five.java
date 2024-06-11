import java.util.Scanner;
public class five {
    public static void main(String[] args) {
        System.out.println("【幸运小猫】>>用户注册");
        Scanner input = new Scanner(System.in);
        System.out.println("请输入用户名：");
        String uName = input.nextLine();
        System.out.println("请输入密码");
        String pwd1 = input.nextLine();
        System.out.println("请确认密码：");
        String pwd2 = input.nextLine();
        if (pwd1.equals(pwd2)){
            System.out.println("【"+uName+"】注册成功！");
        }
    }
}