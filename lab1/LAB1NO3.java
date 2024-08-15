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
public class LAB1NO3 {
    public static void main (String [] args){
        System.out.println("Enter three points of triangle: ");
        double x1, y1;
        double x2, y2;
        double x3, y3;
        Scanner input = new Scanner(System.in);
        x1 = input.nextDouble();
        y1 = input.nextDouble();
        x2 = input.nextDouble();
        y2 = input.nextDouble();
        x3 = input.nextDouble();
        y3 = input.nextDouble();
        double side1 = Math.sqrt((Math.pow(x1 - x2, 2)) + (Math.pow(y1 - y2, 2)));
        double side2 = Math.sqrt((Math.pow(x1 - x3, 2)) + (Math.pow(y1 - y3, 2)));
        double side3 = Math.sqrt((Math.pow(x2 - x3, 2)) + (Math.pow(y2 - y3, 2)));
        double s = (side1 + side2 + side3) / 2;
        double cal = Math.sqrt((s * ((s - side1) * (s - side2) * (s - side3))));
        String formattedCalculation = String.format("%.1f", cal);
        System.out.println(formattedCalculation);
        System.out.println("==============================");
    }
}
