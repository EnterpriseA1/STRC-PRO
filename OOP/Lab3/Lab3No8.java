package javaapplication2;

import java.util.Scanner;

public class Lab3No8 {

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
