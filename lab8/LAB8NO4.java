/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;

import java.util.*;
/**
 *
 * @author studentcs
 */
abstract class Employee {
    public String firstname;
    public String lastname;
    public String id;
    public Employee(String firstname, String lastname, String id) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.id = id;
    }
    public abstract double earning();
    public abstract int getYear();
    public abstract double bonus(int year);
}
class SalariedEmployee extends Employee {
    double salary;
    int year;
    public SalariedEmployee(String firstname,String lastname,String id,int year,double sal){
        super(firstname,lastname,id);
        this.year = year;
        this.salary = sal;
    }
    @Override
    public double bonus(int year){
        if (this.year > 5){
            return salary * 12;
        }
        else{
            return salary * 6;
        }
    }
    @Override
    public double earning(){
        return salary * 0.95;
    }
    @Override
    public int getYear(){
        return this.year;
    }
}
class ComEmployee extends Employee{
    double grossSale;
    double ComRate;
    int year;
    public ComEmployee(String firstname,String lastname,String id,int year,double sales, double percent){
        super(firstname,lastname,id);
        this.year = year;
        this.grossSale = sales;
        this.ComRate = percent;
    }
    @Override
    public double bonus(int year){
        if (this.year > 5){
            return grossSale * 6;
        }
        else{
            return grossSale * 3;
        }
    }
    @Override
    public double earning(){
        return grossSale+(grossSale * ComRate);
    }
    @Override
    public int getYear(){
        return this.year;
    }
   
}
