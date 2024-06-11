package j240416;

public class CheckAccount extends Account {
    private double overdraft; // 可透支限额

    // 构造方法
    public CheckAccount(String accountId, double balance, double annualInterestRate, double overdraft) {
        super(accountId, balance, annualInterestRate);
        this.overdraft = overdraft;
    }

    // 重写 withdraw 方法
    @Override
    public void withdraw(double amount) {
        if (amount <= getBalance()) {
            // 可直接取款
            super.withdraw(amount);
        } else {
            // 计算需要透支的额度
            double overdraftNeeded = amount - getBalance();
            if (overdraftNeeded <= overdraft) {
                // 可透支额度足够支付本次透支需要
                setBalance(0); // 将账户余额修改为0
                overdraft -= overdraftNeeded; // 冲减可透支金额
                System.out.println("透支" + overdraftNeeded + "元，当前余额为0，可透支额为" + overdraft + "元");
            } else {
                // 超过可透支额的限额
                System.out.println("超过可透支额的限额");
            }
        }
    }

    // 获取可透支额
    public double getOverdraft() {
        return overdraft;
    }

    // 设置可透支额
    public void setOverdraft(double overdraft) {
        this.overdraft = overdraft;
    }

    public static void main(String[] args) {
        // 创建 CheckAccount 对象
        CheckAccount checkAcc = new CheckAccount("1122", 20000, 4.5, 5000);
        System.out.println("账户余额：" + checkAcc.getBalance());
        System.out.println("可透支额：" + checkAcc.getOverdraft());

        // 测试取款
        checkAcc.withdraw(15000); // 直接取款
        checkAcc.withdraw(30000); // 透支
        checkAcc.withdraw(8000); // 超过可透支额

        System.out.println("最终账户余额：" + checkAcc.getBalance());
        System.out.println("最终可透支额：" + checkAcc.getOverdraft());
    }
}

