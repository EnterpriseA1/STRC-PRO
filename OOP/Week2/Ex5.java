/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week2;

import java.util.Scanner;

public class Ex5 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();
        double d = input.nextDouble();
        double e = input.nextDouble();
        double f = input.nextDouble();

        equation x = new equation(a, b, c, d, e, f);
        equation y = new equation(a, b, c, d, e, f);
        if (x.isSolvable(x) && y.isSolvable(y)) {
            x.calcX(x);
            x.getX();
            y.calcY(y);
            y.getY();
        } else {
            System.out.println("The equation has no solution");
        }
    }
}

class equation {

    private double a, b, c, d, e, f, x, y;

    public void setValue(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }

    public equation(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }

    public boolean isSolvable(equation x) {
        double temp = x.a * x.d - x.b * x.c;
        if (temp != 0) {
            return true;
        } else {
            return false;
        }
    }

    public void calcX(equation temp) {
        double numerator = (temp.e * temp.d) - (temp.b * temp.f);
        double denominator = (temp.a * temp.d) - (temp.b * temp.c);
        this.x = numerator / denominator;
    }

    public void calcY(equation temp) {
        double numerator = (temp.a * temp.f) - (temp.e * temp.c);
        double denominator = (temp.a * temp.d) - (temp.b * temp.c);
        this.y = numerator / denominator;
    }

    public void getX() {
        System.out.print("x is " + this.x);
    }

    public void getY() {
        System.out.println(" y is " + this.y);
    }
}
