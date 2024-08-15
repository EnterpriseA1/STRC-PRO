/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week2;

public class Ex1 {

    public static void main(String args[]) {
        Complex a = new Complex(1.0, 2.0);
        Complex b = new Complex(3.0, 4.0);
        Complex c = new Complex(a);
        c.add(b);
        c.print();
        c.reset(1.0, 2.0);

        c.sub(b);
        c.print();
        c.reset(1.0, 2.0);

        c.mul(b);
        c.print();
        c.reset(1.0, 2.0);

        c.div(b);
        c.print();
    }
}

class Complex {

    private double r, i;

    public void reset(double r, double i) {
        this.r = r;
        this.i = i;
    }

    public void getValue() {
        System.out.println(this.r + ", " + this.i);
    }

    Complex(double r, double i) {
        this.r = r;
        this.i = i;
    }

    Complex(Complex c) {
        this(c.r, c.i);
    }

    public void add(Complex c) {
        double tempR = r + c.r;
        double tempI = i + c.i;
        r = tempR;
        i = tempI;
    }

    public void sub(Complex c) {
        double tempR = r - c.r;
        double tempI = i - c.i;
        r = tempR;
        i = tempI;
    }

    public void mul(Complex c) {
        double tempR = this.r * c.r - this.i * c.i;
        double tempI = this.r * c.i + this.i * c.r;
        r = tempR;
        i = tempI;
    }

    public void div(Complex c) {
        double denominator = c.r * c.r + c.i * c.i;
        double tempR = (this.r * c.r + this.i * c.i) / denominator;
        double tempI = (this.i * c.r - this.r * c.i) / denominator;
        r = tempR;
        i = tempI;
    }

    public void print() {
        System.out.println(r + " + " + i + "i");
    }
}
