package Week2;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.util.Scanner;

public class Ex6 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input id : ");
        int id = input.nextInt();

        System.out.print("Input balance : ");
        double bal = input.nextDouble();
        Account account = new Account(id, bal);

        account.setRate(0.045);

        System.out.print("Input Money (Withdraw) : ");
        double money = input.nextDouble();
        account.withdraw(money);

        System.out.print("Input Money (Deposit) : ");
        money = input.nextDouble();
        account.deposit(money);
        System.out.println("");
        account.getInfo();
    }
}

class Date {

    private int date, month, year;

    Date() {
        this(17, 07, 2024);
    }

    public Date(int date, int month, int year) {
        this.date = date;
        this.month = month;
        this.year = year;
    }

    public String toString() {
        return date + "/" + month + "/" + year;
    }
}

class Account {

    private int id;
    private double balance;
    private double annualInterestRate;
    private Date date = new Date();

    Account() {
        this.id = 0;
        this.balance = 0.0;
        this.annualInterestRate = 0.0;
    }

    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
    }

    public void getInfo() {
        System.out.println("id : " + this.id);
        System.out.println("balance : " + this.balance);
        System.out.println("annualInterestRest : " + this.annualInterestRate + "%");
        System.out.println("Date created : " + date.toString());
        System.out.println("monthlyInterestRate : " + getMonthlyInterestRate() + "%");
    }

    public void setID(int x) {
        this.id = x;
    }

    public void setBalance(double x) {
        this.balance = x;
    }

    public void setRate(double x) {
        this.annualInterestRate = x;
    }

    public void setDate(Date d) {
        this.date = d;
    }

    public double getMonthlyInterestRate() {
        return this.annualInterestRate / 12;
    }

    public double getMonthlyInterest() {
        double temp = getMonthlyInterestRate();
        return this.balance * temp;
    }

    public void withdraw(double x) {
        this.balance -= x;
    }

    public void deposit(double x) {
        this.balance += x;
    }
}
