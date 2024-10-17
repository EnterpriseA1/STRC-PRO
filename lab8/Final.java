/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;
import java.util.*;
import javax.swing.*;
/**
 *
 * @author studentcs
 */
public class Final {
    public static void main(String[] args) {
        ArrayList<Employee> employees = new ArrayList<>();
        SalariedEmployee newEmp1 = new SalariedEmployee("John","Doe","1121",6,10000);
        employees.add(newEmp1);
        SalariedEmployee newEmp2 = new SalariedEmployee("Alex","Maxwell","1279",5,10000);
        employees.add(newEmp2);
        ComEmployee newEmp3 = new ComEmployee("Dionel","Atlast","2031",6,10000,10.0);
        employees.add(newEmp3);
        ComEmployee newEmp4 = new ComEmployee("Nick","Atlast","2031",5,20000,20.0);
        employees.add(newEmp4);
        printEmp(employees);
        
    }
    public static void printEmp(ArrayList<Employee> a) {
    
        StringBuilder sb = new StringBuilder();
        
        sb.append(String.format("%-15s %-15s %-10s %-10s%n", "First Name", "Last Name", "Earning", "Bonus"));
        sb.append("--------------------------------------------------\n");
        
        for (Employee y : a) {
            sb.append(String.format("%-15s %-15s %-10.2f %-10.2f%n", 
                y.firstname, 
                y.lastname, 
                y.earning(), 
                y.bonus(y.getYear())
            ));
        }
        JOptionPane.showMessageDialog(null, sb.toString(), "Employee Information", JOptionPane.INFORMATION_MESSAGE);
    }
}