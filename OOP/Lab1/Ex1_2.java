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
public class Ex1_2 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double fh;
        double c;
        fh = input.nextDouble();
        c = (5.0 / 9.0) * (fh - 32);
        System.out.println("Celsius = " + c);
    }
}
