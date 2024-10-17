/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;

/**
 *
 * @author Kkhamwiset
 */
class Circle extends GeometricObject implements Comparable<Circle> {
    private double r;

    public Circle(double r) {
        this.r = r;
    }
    public double getRadius() {
        return r;
    }

    public void setRadius(double r) {
        this.r = r;
    }

    @Override
    public double getArea() {
        return Math.PI * r * r;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * r;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        Circle other = (Circle) obj;
        return Double.compare(r, other.r) == 0;
    }

    @Override
    public int compareTo(Circle other) {
        return Double.compare(this.r, other.r) == 0 ? 1 : 0;
    }

    @Override
    public String toString() {
        return "Circle with radius: " + r + ", color: " + getColor() + ", filled: " + isFilled();
    }
}
public class LAB8NO5{
    public static void main(String[] args) {
        Circle firstCircle = new Circle(2.0);
        Circle secondCircle = new Circle(2.0);
        System.out.println(firstCircle.compareTo(secondCircle));
        System.out.println(firstCircle.equals(secondCircle));
    }
}