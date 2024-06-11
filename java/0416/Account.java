package j240416;

public class Account {
    private String accountId;
    private double balance;
    private double annualInterestRate;
    // 构造方法
    public Account(String accountId, double balance, double annualInterestRate) {
        this.accountId = accountId;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
    }
    // 获取器和设置器方法
    public String getAccountId() {
        return accountId;
    }
    public void setAccountId(String accountId) {
        this.accountId = accountId;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }
    public double getAnnualInterestRate() {
        return annualInterestRate;
    }
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }
    public double getMonthlyInterest() {
        double monthlyInterestRate = annualInterestRate / 12 / 100;
        return balance * monthlyInterestRate;
    }
    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("余额不足。");
        } else {
            balance -= amount;
            System.out.println("取款成功。当前余额为：" + balance);
        }
    }
    public void deposit(double amount) {
        balance += amount;
        System.out.println("存款成功。当前余额为：" + balance);
    }
    public static void main(String[] args) {
        Account acc = new Account("12345", 1000, 5);
        System.out.println("账户ID：" + acc.getAccountId());
        System.out.println("当前余额：" + acc.getBalance());
        System.out.println("月利息：" + acc.getMonthlyInterest());
        acc.withdraw(500);
        acc.deposit(200);
        System.out.println("更新后余额：" + acc.getBalance());
    }
}

