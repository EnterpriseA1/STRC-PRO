/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab1;
import java.util.Scanner;

/**
 *
 * @author KKhamvised
 */
public class LAB1NO4 {
    public static void main (String[] args){
        System.out.println("Enter balance and interest rate (e.g., 3 for 3%): ");
        double balance, rate = 0.00, annual;
        Scanner input = new Scanner(System.in);
        balance = input.nextDouble();
        annual = input.nextDouble();
        rate = balance * (annual / 1200);
        String formattedString = String.format("%6f", rate);
        System.out.println(formattedString);
        System.out.println("==============================");
    }
}
