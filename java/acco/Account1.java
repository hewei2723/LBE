package acco;

public class Account1 {
    // 定义私有变量id，balance，annualInterestRate
    private int id;
    private  int balance;
    private double annualInterestRate;
    // 定义无参构造函数
    // 定义getAnnualInterestRate()方法，返回annualInterestRate
    public double getAnnualInterestRate() {
        return annualInterestRate;
    }
    // 定义setAnnualInterestRate()方法，设置annualInterestRate
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }
    // 定义getId()方法，返回id
    public int getId() {
        return id;
    }
    // 定义setId()方法，设置id
    public void setId(int id) {
        this.id = id;
    }
    // 定义getBalance()方法，返回balance
    public int getBalance() {
        return balance;
    }
    // 定义setBalance()方法，设置balance
    public void setBalance(int balance) {
        this.balance = balance;
    }
    // 定义有参构造函数
    public Account1(int id, int balance, double annualInterestRate) {
        this.id=id;
        this.balance=balance;
        this.annualInterestRate=annualInterestRate;
    }
    // 定义getMonthlyInterestRate()方法，返回每月利息
    public int getMonthlyInterestRate() {
        return (int) (balance * annualInterestRate / 1200);
    }
    // 定义withdraw()方法，取款
    public int withdraw(int amount) {
        return balance -= amount;
    }
    // 定义deposit()方法，存款
    public int deposit(int amount) {
        return balance += amount;
    }
}