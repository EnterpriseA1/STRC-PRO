/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;

/**
 *
 * @author KKhamvised
 */
abstract class GeometricObject {
    private String color = "white";
    private boolean filled;
    /** Default constructor */
    protected GeometricObject() {
    }
    /** Convenience constructor */
    protected GeometricObject(String color, boolean filled) {
    this.color = color;
    this.filled = filled;
    }
    public String getColor() {
    return color;
    }
    public void setColor(String color) {
    this.color = color;
    }
    public boolean isFilled() {
    return filled;
    }
    public void setFilled(boolean filled) {
    this.filled = filled;
    }
    public abstract double findArea();
    public abstract double findPerimeter();
}
class Rectangle extends GeometricObject {
    private double width;
    private double height;

    public Rectangle() {
    }

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    public Rectangle(double width, double height, String color, boolean filled) {
        super(color, filled); 
        this.width = width;
        this.height = height;
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

    @Override
    public double findArea() {
        return getArea();
    }

    @Override
    public double findPerimeter() {
        return getPerimeter();
    }
}


