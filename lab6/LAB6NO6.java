/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab6;
import java.util.*;
import java.time.*;

class Date {
    private int day, year;
    private String month;

    Date() {
    }

    Date(int day, String month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int getDay() {
        return day;
    }

    public String getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    @Override
    public String toString() {
        return day + " " + month + " " + year;
    }
}

class Person {
    private String name, surname;
    private int age;
    private Date bDate;
    Person() {}
    Person(String name, String surname, int age, Date bDate) {
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.bDate = bDate;
    }
    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }

    public Date getBDate() {
        return bDate;
    }

    @Override
    public String toString() {
        return name + " " + surname + "\n, Age: " + age + "\n, Born on: " + bDate;
    }
}
class Account {
    private double balance, annualInterestRate;
    private int id;
    private Date dateCreated;
    private Person objPerson;

    Account() {
        this.balance = 0;
        this.annualInterestRate = 0;
        this.dateCreated = new Date(1, "January", 2024);
    }

    Account(int id, double annualInterestRate, double balance, Date dateCreated,Person owner) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        this.dateCreated = dateCreated;
        this.objPerson = owner;
    }
    
    public void withdraw(double value) {
        System.out.printf("\n%s withdraw : %f\n",this.objPerson.getName(),value);
        if (value <= this.balance) {
            this.balance -= value;
        } else {
            System.out.println("Insufficient funds.");
        }
    }

    public void deposit(double value) {
        System.out.printf("\n%s deposit : %f\n",this.objPerson.getName(),value);
        if (value > 0) {
            this.balance += value;
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    public void transferMoney(Account acc1, double amount) {
        if (this.balance >= amount + 20) {
            this.withdraw(amount);
            acc1.deposit(amount - 20);
        } else {
            System.out.println("Insufficient funds for transfer.");
        }
    }
    public double getMonthlyInterest(){
        double monthlyInterestRate = getMonthlyInterestRate() / 100;
        LocalDate currentDate = LocalDate.now();
        int day = dateCreated.getDay();
        int month = FixAccount.monthToInt(dateCreated.getMonth());
        int year = dateCreated.getYear();
        LocalDate creationDate = LocalDate.of(year, month, day);
        Period period = Period.between(creationDate, currentDate);
        int daysInMonth = currentDate.lengthOfMonth();
        int daysAccountActive = period.getDays();
        double proportionOfMonthActive = (double) daysAccountActive / daysInMonth;
        double monthlyInterest = balance * monthlyInterestRate * proportionOfMonthActive;
        return monthlyInterest;
    }
    public double getMonthlyInterestRate() {
        return this.annualInterestRate / 12;
    }

    @Override
    public String toString() {
        return String.format(
        "\nID: %d\nBalance: %.2f\nInterest: %.2f\nMonthlyInterestRate: %.2f\nCreated on: %s\n",
        id,
        balance,
        getMonthlyInterest(),
        getMonthlyInterestRate(),
        dateCreated.toString()
        );
    }
}

class SavingAccount extends Account {
    public SavingAccount() {
        super();
    }

    public SavingAccount(int id, double aRate, double balance, Date dateCreated,Person own) {
        super(id, aRate, balance, dateCreated,own);
    }

    @Override
    public void transferMoney(Account acc1, double amount) {
        withdraw(amount);
        acc1.deposit(amount - 20);
    }
}


class FixAccount extends Account {
    private static final Map<String, Integer> monthMap = new HashMap<>();
    static {
        monthMap.put("January", 1);
        monthMap.put("February", 2);
        monthMap.put("March", 3);
        monthMap.put("April", 4);
        monthMap.put("May", 5);
        monthMap.put("June", 6);
        monthMap.put("July", 7);
        monthMap.put("August", 8);
        monthMap.put("September", 9);
        monthMap.put("October", 10);
        monthMap.put("November", 11);
        monthMap.put("December", 12);
    }
    public static Integer monthToInt(String monthName) {
        return monthMap.get(monthName);
    }
    private Date depos = null;
    public FixAccount() {
        super();
    }

    public FixAccount(int id, double aRate, double balance, Date dateCreated,Person own) {
        super(id, aRate, balance, dateCreated,own);
    }
    public void setDepos(Date dateDepos){
        this.depos = dateDepos;
    }
    public void withdraw(int amount,Date withDraw){
        if (depos == null){
            System.out.println("Can't withdraw you haven't deposit any");
        }
        else{
            Integer month = monthToInt(depos.getMonth());
            Integer month_2 = monthToInt(withDraw.getMonth());
            LocalDate startDate = LocalDate.of(depos.getYear(),month,depos.getDay());
            LocalDate endDate = LocalDate.of(withDraw.getYear(),month_2,withDraw.getDay());
            Period period = Period.between(startDate, endDate);
            if (Math.abs(period.getYears()) >= 1){
                withdraw(amount);
            }
            else{
                System.out.println("Can't withdraw, deposit less than 1 years");
            }
            
        }
        
    }
    @Override
    public void transferMoney(Account acc1, double amount) {
        System.out.println("*** Can't transfer money from a Fixed Account. ***");
    }
}

public class LAB6NO6 {
    public static void main(String[] args) {
        Scanner inputPerson = new Scanner(System.in);
        SavingAccount customer1 = inputAccountDetails(inputPerson);
        SavingAccount customer2 = inputAccountDetails(inputPerson);
        customer1.withdraw(2500);
        System.out.println(customer1);
        customer1.deposit(3000);
        System.out.println(customer1);
        System.out.println("");
        System.out.println("Before transfer:");
        System.out.println(customer1);
        System.out.println(customer2);
        customer1.transferMoney(customer2, 1000);
        System.out.println("\nAfter transfer:");
        System.out.println(customer1);
        System.out.println(customer2);
        FixAccount customer3 = inputFixAccountDetails(inputPerson);
        System.out.println(customer3);
        customer3.deposit(3000);
        customer3.setDepos(new Date(14,"August",2024));
        customer3.withdraw(2000,new Date(10, "August", 2022));
        System.out.println(customer3);
        customer3.transferMoney(customer2, 3000);
    }
    
    public static SavingAccount inputAccountDetails(Scanner scanner) {
        System.out.print("Enter ID: ");
        int id = scanner.nextInt();
        System.out.print("Enter Annual Interest Rate: ");
        double aRate = scanner.nextDouble();
        System.out.print("Enter Balance: ");
        double balance = scanner.nextDouble();
        int day;
        String month;
        int year;
        Date dateCreated = new Date(2, "June", 2017);
        scanner.nextLine();
        System.out.print("Enter Person's Name: ");
        String name = scanner.nextLine();
        System.out.print("Enter Person's Surname: ");
        String surname = scanner.nextLine();
        System.out.print("Enter Person's Age: ");
        int age = scanner.nextInt();
//        System.out.print("Enter Person's Birth Date (day month [in text] year): ");
//        day = scanner.nextInt();
//        month = scanner.next();
//        year = scanner.nextInt();
        Date bDate = new Date(5, "June", 2017);
        Person owner = new Person(name, surname, age, bDate);
        return new SavingAccount(id, aRate, balance, dateCreated, owner);
    }
    public static FixAccount inputFixAccountDetails(Scanner scanner) {
        System.out.print("Enter ID: ");
        int id = scanner.nextInt();
        System.out.print("Enter Annual Interest Rate: ");
        double aRate = scanner.nextDouble();
        System.out.print("Enter Balance: ");
        double balance = scanner.nextDouble();
        int day;
        String month;
        int year;
        Date dateCreated = new Date(1, "August", 2015);
        scanner.nextLine();
        System.out.print("Enter Person's Name: ");
        String name = scanner.nextLine();
        System.out.print("Enter Person's Surname: ");
        String surname = scanner.nextLine();
        System.out.print("Enter Person's Age: ");
        int age = scanner.nextInt();
//        System.out.print("Enter Person's Birth Date (day month [in text] year): ");
//        day = scanner.nextInt();
//        month = scanner.next();
//        year = scanner.nextInt();
        Date bDate = new Date(6, "June", 2012);
        Person owner = new Person(name, surname, age, bDate);
        return new FixAccount(id, aRate, balance, dateCreated, owner);
    }
}
