package Week2;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
import java.util.Scanner;

public class Ex8 {

    public static void main(String[] args) {
        RegularPolygon P1 = new RegularPolygon();
        System.out.println("Polygon 1");
        P1.showData();
        System.out.println("");

        RegularPolygon P2 = new RegularPolygon(6, 4);
        System.out.println("Polygon 2");
        P2.showData();
        System.out.println("");

        RegularPolygon P3 = new RegularPolygon(10, 4, 5.6, 7.8);
        System.out.println("Polygon 3");
        P3.showData();
    }
}

class RegularPolygon {

    private int n; //number of sides in polygon
    private double side, x, y;

    /*
        side - length of the side
        x - x-coordinate of the polygon's center
        y - y-coordinate of the polygon's center
     */
    public RegularPolygon() {
        this.n = 3;
        this.side = 1;
        this.x = 0;
        this.y = 0;
    }

    public RegularPolygon(int n, double side) {
        this.n = n;
        this.side = side;
    }

    public RegularPolygon(int n, double side, double x, double y) {
        this.n = n;
        this.side = side;
        this.x = x;
        this.y = y;
    }

    public void showData() {
        System.out.println("Perimeter : " + getPerimeter());
        System.out.println("Area : " + getArea());
    }

    public void setN(int n) {
        this.n = n;
    }

    public void setSide(double s) {
        this.side = s;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getPerimeter() {
        return this.side * this.n;
    }

    public double getArea() {
        return (this.n * Math.pow(this.side, 2)) / (4 * Math.tan(Math.PI / this.n));
    }
}
