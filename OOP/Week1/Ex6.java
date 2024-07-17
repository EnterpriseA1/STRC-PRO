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
public class Ex6 {

    public static void main(String[] args) {
        System.out.print("Please input number of columns and rows:");
        Scanner input = new Scanner(System.in);
        int row = input.nextInt();
        int column = input.nextInt();
        int result;

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= row; j++) {
                result = i * j;
                if (result == 1) {
                    System.out.print("\t");
                } else {
                    System.out.print(result + "\t");
                }
            }
            System.out.println();
        }
    }
}
