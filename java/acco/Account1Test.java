package acco;

public class Account1Test {
    public static void main(String[] args) {
        // 创建一个新的账户对象
        Account1 account = new Account1(1253,1000,3.5);
        Account1 ac1=new Account1(1773,1500,3.8);
        // 设置账户信息
        // 打印账户信息
        System.out.println("账户ID: " + account.getId());
        System.out.println("账户余额: " + account.getBalance());
        System.out.println("年利率: " + account.getAnnualInterestRate() + "%");
        // 打印每月利息
        System.out.println("每月利息: " + account.getMonthlyInterestRate());
        // 取款
        int withdrawAmount = 200;
        System.out.println("取款 " + withdrawAmount + " 后的余额: " + account.withdraw(withdrawAmount));
        // 存款
        int depositAmount = 300;
        System.out.println("存款 " + depositAmount + " 后的余额: " + ac1.deposit(depositAmount));
        System.out.println("账户ID: " + ac1.getId());
        System.out.println("账户余额: " + ac1.getBalance());
        System.out.println("年利率: " + ac1.getAnnualInterestRate() + "%");

    }
}