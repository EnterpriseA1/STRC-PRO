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
public class LAB3NO8 {
      public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int i = input.nextInt();
        m(i);
    }
    public static void m(int x) {
        double ans = 0;
        for (int i = 1; i <= x; i++) {
            double temp = (Math.pow(-1.0, i + 1.0)) / ((2 * i) - 1);
            ans += temp;
        }
        ans *= 4;
        System.out.println("ans = " + String.format("%.4f", ans));
    }
}
