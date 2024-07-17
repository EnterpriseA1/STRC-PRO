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
public class Ex7 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Please input x, n: ");
        int x = input.nextInt();
        int n = input.nextInt();
        int result = 0;
        for (int i = 0; i <= n; i++) {
            result += Math.pow(x, i);
        }
        System.out.println("Output is: " + result);
    }
}
