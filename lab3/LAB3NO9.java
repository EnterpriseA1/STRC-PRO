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
public class LAB3NO9 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter x0, y0, x1, y1, x2, y2: ");
        double x0 = input.nextDouble();
        double y0 = input.nextDouble();
        double x1 = input.nextDouble();
        double y1 = input.nextDouble();
        double x2 = input.nextDouble();
        double y2 = input.nextDouble();
        if (leftOfTheLine(x0, y0, x1, y1, x2, y2)) {
            System.out.println("2");
        } else if (onTheSameLine(x0, y0, x1, y1, x2, y2)) {
            System.out.println("0");
        } else {
            System.out.println("1");
        }
    }
    public static boolean leftOfTheLine(double x0, double y0, double x1, double y1, double x2, double y2) {
        return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) > 0;
    }
    public static boolean onTheSameLine(double x0, double y0, double x1, double y1, double x2, double y2) {
        return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) == 0;
    }
    public static boolean rightOfTheLine(double x0, double y0, double x1, double y1, double x2, double y2) {
        return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) < 0;
    }
}   
