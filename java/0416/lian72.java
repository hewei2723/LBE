package j240416;

public class lian72 {
    private int id;
    private double balance;
    private double annualInterestRate;

    public lian72(int id, double balance, double annualInterestRate) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    public double getMonthlyInterestRate() {
        return annualInterestRate / 12;
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("余额不足，取款失败！");
        } else {
            balance -= amount;
            System.out.println("成功取款：" + amount + "元");
        }
    }

    public void deposit(double amount) {
        balance += amount;
        System.out.println("成功存款：" + amount + "元");
    }

    public static void main(String[] args) {
        lian72 account = new lian72(1122, 20000, 4.5);

        System.out.println("提款30000元...");
        account.withdraw(30000);
        System.out.println("当前余额：" + account.getBalance());

        System.out.println("\n提款2500元...");
        account.withdraw(2500);
        System.out.println("当前余额：" + account.getBalance());

        System.out.println("\n存款3000元...");
        account.deposit(3000);
        System.out.println("当前余额：" + account.getBalance());
        System.out.println("月利率为：" + account.getMonthlyInterestRate() + "%");
    }
}