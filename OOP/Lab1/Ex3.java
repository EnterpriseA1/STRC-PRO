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
public class Ex3 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double s, side1, side2, side3;
        System.out.print("Enter three points for a triangle: ");
        x1 = input.nextDouble();
        y1 = input.nextDouble();
        x2 = input.nextDouble();
        y2 = input.nextDouble();
        x3 = input.nextDouble();
        y3 = input.nextDouble();

        side1 = Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));
        side2 = Math.sqrt(Math.pow(x1 - x3, 2) + Math.pow(y1 - y3, 2));
        side3 = Math.sqrt(Math.pow(x2 - x3, 2) + Math.pow(y2 - y3, 2));
        s = (side1 + side2 + side3) / 2.0;

        double area = Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
        String result = String.format("%.1f", area);
        System.out.println("The area of the triangle is " + result);
    }
}
