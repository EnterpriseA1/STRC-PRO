/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab2;

/**
 *
 * @author KKhamvised
 */
class Date{
    private int date,month,year;
    Date(int date,int month,int year){
        this.date = date;
        this.month = month;
        this.year = year;
    }
    @Override
    public String toString(){
        return this.date + "/" + this.month + "/" + this.year;
    }
}
class Account{
    private double balance,annualInterestRate;
    private int id;
    private Date dateCreated;
    Account(){
        this.balance = 0;
        this.annualInterestRate = 0;
        this.dateCreated = new Date(17,7,2024);
    }
    Account(int id,double annualInterestRate,double balance){
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        this.dateCreated = new Date(17,7,2024);
    }
    public void get(){
        System.out.println("====================================================");
        System.out.println("ID : " + this.id);
        System.out.println("Balance : " + this.balance);
        System.out.println("MonthlyInterestRate : " + this.getMonthlyInterestRate());
        System.out.println("Created since : " + this.dateCreated.toString());
        
    }
    public void set(int id,double balance,double annualInterestRate,Date datecreated){
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        this.dateCreated = datecreated;
    }
    public double getMonthlyInterestRate(){
        return this.annualInterestRate / 12;
        
    }
    public double getMonthlyInterest(){
        double monthlyInterestRate = getMonthlyInterestRate();
        return balance * monthlyInterestRate;
    }
    public void withdraw(int value){
        this.balance -= value;
    }
    public void deposit(int value){
        this.balance += value;
    }
    
}
public class LAB2NO6 {
    public static void main(String[]args){
        Account client1 = new Account();
        client1.set(1112,20000,4.5,new Date(17,7,2024));
        client1.get();
        client1.withdraw(2500);
        client1.get();
        client1.deposit(3000);
        client1.get();
    }
}
