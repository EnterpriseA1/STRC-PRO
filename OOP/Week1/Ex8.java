/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week1;

import java.util.Scanner;
import javax.print.DocFlavor;

/**
 *
 * @author Asus
 */
public class Ex8 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please input n, a0 and a1: ");
        int n = input.nextInt();
        double a0 = input.nextInt();
        double a1 = input.nextInt();
        double previous_1 = a0;
        double previous_2 = a1;
        double result = 0;
        System.out.print((int) (a0) + " " + (int) (a1) + " ");
        for (int k = 2; k <= n; k++) {
            if (k > 2) {
                result = Math.pow(k, 2) * previous_2 - previous_1 + Math.pow(3, k);
                previous_1 = previous_2;
                previous_2 = result;
                System.out.print((int) (result) + " ");
            } else {
                result = Math.pow(k, 2) * previous_2 - previous_1 + Math.pow(3, k);
                previous_1 = previous_2;
                previous_2 = result;

                System.out.print((int) (result) + " ");
            }
        }
    }
}
