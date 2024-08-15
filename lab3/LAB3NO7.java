/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab3;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
class MyTriangle {
    public boolean isValid(double side1, double side2, double side3) {
        if ((side1 + side2) > side3) {
            return true;
        }
        return false;
    }

    public double area(double side1, double side2, double side3) {
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
}
public class LAB3NO7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double side1 = input.nextDouble();
        double side2 = input.nextDouble();
        double side3 = input.nextDouble();
        MyTriangle triangle = new MyTriangle();

        if (triangle.isValid(side1, side2, side3) == true) {
            System.out.println(String.format("%.2f", triangle.area(side1, side2, side3)));
        } else {
            System.out.println("0");
        }
    }
}
