/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab6;

/**
 *
 * @author KKhamvised
 */
class Rectangle {
    int width, height;
    int x, y;
    public Rectangle() {
        this.width = 0;
        this.height = 0;
        this.x = 0;
        this.y = 0;
    }

    public Rectangle(int width, int height, int x, int y) {
        this.width = width;
        this.height = height;
        this.x = x;
        this.y = y;
    }
    public int getArea() {
        return width * height;
    }
    public boolean overlaps(Rectangle b) {
        return this.x < b.x + b.width &&
               this.x + this.width > b.x &&
               this.y < b.y + b.height &&
               this.y + this.height > b.y;
    }
}
class Line {
    int x1, y1, x2, y2;
    public Line() {
        this.x1 = 0;
        this.y1 = 0;
        this.x2 = 0;
        this.y2 = 0;
    }
    public Line(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }

    public double getLength() {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

    public boolean contains(Rectangle b) {
        return (x1 >= b.x && y1 >= b.y && x1 <= b.x + b.width && y1 <= b.y + b.height) &&
               (x2 >= b.x && y2 >= b.y && x2 <= b.x + b.width && y2 <= b.y + b.height);
    }
    public boolean cross(Rectangle b) {
        return !this.contains(b) && (
                intersects(x1, y1, x2, y2, b.x, b.y, b.x + b.width, b.y) ||
                intersects(x1, y1, x2, y2, b.x, b.y, b.x, b.y + b.height) ||
                intersects(x1, y1, x2, y2, b.x + b.width, b.y, b.x + b.width, b.y + b.height) ||
                intersects(x1, y1, x2, y2, b.x, b.y + b.height, b.x + b.width, b.y + b.height)
        );
    }

    public double distance(Rectangle b) {
        double centerX = b.x + b.width / 2.0;
        double centerY = b.y + b.height / 2.0;
        double dist = Math.abs((y2 - y1) * centerX - (x2 - x1) * centerY + x2 * y1 - y2 * x1) / getLength();
        return dist;
    }
    private boolean intersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denominator == 0){
            return false;
        }

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

        return t >= 0 && t <= 1 && u >= 0 && u <= 1;
    }
}
public class LAB6NO8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle(4, 5, 1, 1);
        Rectangle rect2 = new Rectangle(3, 4, 3, 3);
        Line line = new Line(2, 2, 5, 5);
        System.out.println("Line inside rectangle: " + line.contains(rect1));
        System.out.println("Line crosses rectangle: " + line.cross(rect1));
        System.out.println("Rectangles overlap: " + rect1.overlaps(rect2));
        System.out.printf("Distance from line to rectangle center:  %.2f\n",line.distance(rect1));
    }
}
