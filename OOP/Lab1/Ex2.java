/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week1;

import java.util.Scanner;

/**
 *
 * @author studentcs
 */
public class Ex2 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the monthly saving amount: ");
        int deposit = input.nextInt();
        double total = 100;
        double recentMonth = 0;

        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                total = deposit * (1.00 + 0.00417);
                recentMonth = total;
            } else {
                total = (deposit + recentMonth) * (1.00 + 0.00417);
                recentMonth = total;
            }
        }

        String result = String.format("%.2f", total);
        System.out.println("After the six month, the account value is $" + result);
    }
}
