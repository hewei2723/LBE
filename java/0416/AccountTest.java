package j240416;
import java.util.Scanner;

public class AccountTest {
    public static void main(String[] args) {
        // 创建账户对象
        Account acc = new Account("1122", 20000, 4.5);
        Scanner scanner = new Scanner(System.in);

        // 用户输入取款金额
        System.out.print("请输入取款金额：");
        double withdrawAmount = scanner.nextDouble();

        // 尝试提款
        System.out.println("尝试提款" + withdrawAmount + "元...");
        if (withdrawAmount > acc.getBalance()) {
            System.out.println("余额不足");
        } else {
            acc.withdraw(withdrawAmount);
            System.out.println("账户余额为：" + acc.getBalance());
        }
        // 继续按照固定顺序执行操作
        System.out.println("下面将为您提款2500元...");
        acc.withdraw(2500);
        System.out.println("账户余额为：" + acc.getBalance());

        System.out.println("再取款3000元...");
        acc.withdraw(3000);
        System.out.println("账户余额为：" + acc.getBalance());

        // 打印月利率
        System.out.println("月利率为：" + acc.getMonthlyInterest());
        scanner.close(); // 关闭输入流
    }
}


