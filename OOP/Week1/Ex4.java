/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week1;

import java.util.Scanner;

/**
 *
 * @author Asus
 */
public class Ex4 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter balance and interest rate (e.g., 3 for 3%) :");
        double balance = input.nextDouble();
        double rate = input.nextDouble();
        double interest = balance * (rate / 1200);
        String result = String.format("%.5f", interest);
        System.out.println(result);
    }
}
