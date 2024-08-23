/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab6;
import java.util.Scanner;
/**
 *
 * 
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
    public double getLong() {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }
}
/**
 *
 * @author studentcs
 */
public class LAB6NO8 {
     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Rectangle rect1 = getRectangle(in);
        Rectangle rect2 = getRectangle(in);
        Line line = getLine(in);
        Line line2 = getLine(in);
        System.out.println("Line inside rectangle: " + contains(line,rect1));
        System.out.println("Line crosses Line2 : " + cross(line,line2));
         System.out.println("Rect1 overlab Rect2 : " + overlap(rect1,rect2));
        System.out.printf("Distance from Line to rectangle center:  %.2f\n",distance(line,rect1));
    }
    public static int overlap(Rectangle a, Rectangle b) {
        return a.x < b.x + b.width &&
               a.x + a.width > b.x &&
               a.y < b.y + b.height &&
               a.y + a.height > b.y ? 1 : 0;
    }
    public static int cross(Line a,Line b) {
        return intersects(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1,b.x2,b.y2) && (a.x1 != b.x1) ? 1 : 0;
    }
    public static int contains(Line a,Rectangle b) {
        return (a.x1 >= b.x && a.y1 >= b.y && a.x1 <= b.x + b.width && a.y1 <= b.y + b.height) &&
               (a.x2 >= b.x && a.y2 >= b.y && a.x2 <= b.x + b.width && a.y2 <= b.y + b.height) ? 1 : 0;
    }
    public static boolean intersects(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (denominator == 0){
            return false;
        }

        double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
        double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / denominator;

        return t >= 0 && t <= 1 && u >= 0 && u <= 1;
    }
     public static double distance(Line a,Rectangle b) {
        double centerX = b.x + (b.width / 2.0);
        double centerY = b.y - (b.height / 2.0);
        double centerXLine = a.x1 + ((a.x2 - a.x1) / 2.0);
        double centerYLine = a.y1 + ((a.y2 - a.y1) / 2.0);
        double dist = Math.sqrt(Math.pow(centerXLine - centerX, 2) + Math.pow(centerYLine - centerY, 2));
        return dist;
    }
     public static Rectangle getRectangle(Scanner in){
         int w,h,x,y;
         System.out.println("Enter x y of left corner : ");
         x = in.nextInt();
         y = in.nextInt();
         System.out.println("Enter width height : ");
         w = in.nextInt();
         h = in.nextInt();
         Rectangle newRect = new Rectangle(w,h,x,y);
         return newRect;
     }
     public static Line getLine(Scanner in){
         int x1,x2,y1,y2;
         System.out.println("Enter x1 y1 x2 y2");
         x1 = in.nextInt();
         y1 = in.nextInt();
         x2 = in.nextInt();
         y2 = in.nextInt();
         Line newLine = new Line(x1,y1,x2,y2);
         return newLine;
     }
}
