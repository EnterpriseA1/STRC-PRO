/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author KKhamvised
 */
class MyRectangle2D {
    private double x;
    private double y;
    private double width;
    private double height;
    public MyRectangle2D() {
        this.x = 0;
        this.y = 0;
        this.width = 1;
        this.height = 1;
    }

    public MyRectangle2D(double x, double y, double width, double height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }
    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }
    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
    public double getArea() {
        return width * height;
    }
    public double getPerimeter() {
        return 2 * (width + height);
    }
    public boolean contains(double x, double y) {
        return x > this.x - width / 2 && x < this.x + width / 2 &&
               y > this.y - height / 2 && y < this.y + height / 2;
    }
    public boolean contains(MyRectangle2D r) {
        return r.getX() - r.getWidth() / 2 >= this.x - this.width / 2 &&
               r.getX() + r.getWidth() / 2 <= this.x + this.width / 2 &&
               r.getY() - r.getHeight() / 2 >= this.y - this.height / 2 &&
               r.getY() + r.getHeight() / 2 <= this.y + this.height / 2;
    }
    public boolean overlaps(MyRectangle2D r) {
        return !(r.getX() + r.getWidth() / 2 <= this.x - this.width / 2 ||
                 r.getX() - r.getWidth() / 2 >= this.x + this.width / 2 ||
                 r.getY() + r.getHeight() / 2 <= this.y - this.height / 2 ||
                 r.getY() - r.getHeight() / 2 >= this.y + this.height / 2);
    }
}
public class LAB6NO7 {
    public static void main(String[] args) {
        MyRectangle2D r1 = new MyRectangle2D(2, 2, 5.5, 4.9);
        MyRectangle2D r2 = new MyRectangle2D(4, 5, 10.5, 3.2);
        MyRectangle2D r3 = new MyRectangle2D(3, 3, 2.5, 2.5);
        System.out.printf("Area of r1: %.2f\n" , r1.getArea());
        System.out.printf("Perimeter of r1: %.2f\n" , r1.getPerimeter());
        System.out.println("r1 contains point (3, 3): " + r1.contains(3, 3));
        System.out.println("r1 contains r2: " + r1.contains(r2));
        System.out.println("r1 contains r3: " + r1.contains(r3));
        System.out.println("r1 overlaps with r2: " + r1.overlaps(r2));
        System.out.println("r1 overlaps with r3: " + r1.overlaps(r3));
    }
}
