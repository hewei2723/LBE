package j240416;

public class CheckAccountTest {
    public static void main(String[] args) {
        // 创建 CheckAccount 对象
        CheckAccount checkAcc = new CheckAccount("1122", 20000, 4.5, 5000);

        // 测试提款5000元，并打印账户余额和可透支额
        System.out.println("提款5000元...");
        checkAcc.withdraw(5000);
        System.out.println("当前账户余额：" + checkAcc.getBalance());
        System.out.println("当前可透支额：" + checkAcc.getOverdraft());

        // 测试提款18000元，并打印账户余额和可透支额
        System.out.println("提款18000元...");
        checkAcc.withdraw(18000);
        System.out.println("当前账户余额：" + checkAcc.getBalance());
        System.out.println("当前可透支额：" + checkAcc.getOverdraft());

        // 测试提款3000元，并打印账户余额和可透支额
        System.out.println("提款3000元...");
        checkAcc.withdraw(3000);
        System.out.println("当前账户余额：" + checkAcc.getBalance());
        System.out.println("当前可透支额：" + checkAcc.getOverdraft());
    }
}
