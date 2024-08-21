/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;
import java.util.*;
/**
 *
 * @author KKhamvised
 */
class Employee {
    private String firstname;
    private String lastname;
    private String id;
    private double salary;
    private int year;
    public Employee(String firstname, String lastname, String id, double salary,int y) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.id = id;
        this.salary = salary;
        this.year = y;
    }
    public double earning() {
        return salary * 0.05;
    }

    public double bonus() {
        if (year >= 5) {
            return salary * 12;
        } else {
            return salary * 0.06;
        }
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public String getId() {
        return id;
    }

    public double getSalary() {
        return salary;
    }
    public int getYear(){
        return year;
    }
}

public class LAB5NO5 {
    public static void main(String[] args) {
        ArrayList<Employee> arrayEarn = new ArrayList<>();
        int n;
        System.out.println("Enter Employee amount : ");
        Scanner in = new Scanner(System.in);
        n =  in.nextInt();
        in.nextLine();
        for (int i = 0 ; i < n; i++){
            String firstname,lastname,id;
            int year;
            double salary;
            System.out.println("Enter First name: ");
            firstname = in.nextLine();
            System.out.println("Enter Last name: ");
            lastname = in.nextLine();
            System.out.println("Enter id salary year: ");
            id = in.next();
            salary = in.nextDouble();
            year = in.nextInt();
            Employee newStaff = new Employee(firstname,lastname,id,salary,year);
            arrayEarn.add(newStaff);
            in.nextLine();
        }
        printEmp(arrayEarn);
    }
    public static void printEmp(ArrayList<Employee> arrayEarn) {
        System.out.printf("%-15s %-15s %-15s %-15s\n", "First Name", "Last Name", "Earning", "Bonus");
        for (Employee emp : arrayEarn) {
            double earning = emp.earning();
            double bonus = emp.bonus();
            System.out.printf("%-15s %-15s %-15.2f %-15.2f\n", emp.getFirstname(), emp.getLastname(), earning, bonus);
        }
    }
}
