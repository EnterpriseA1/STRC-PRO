/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab2;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
class Rectangle{
    private double coorX,coorY,width,height;
    void get(){
        Scanner input = new Scanner(System.in);
        this.coorX = input.nextDouble();
        this.coorY = input.nextDouble();
        this.width = input.nextDouble();
        this.height = input.nextDouble();
    }
   boolean isOverlap(Rectangle b) {
        double thisLeft = this.coorX - this.width / 2;
        double thisRight = this.coorX + this.width / 2;
        double thisBottom = this.coorY - this.height / 2;
        double thisTop = this.coorY + this.height / 2;

        double bLeft = b.coorX - b.width / 2;
        double bRight = b.coorX + b.width / 2;
        double bBottom = b.coorY - b.height / 2;
        double bTop = b.coorY + b.height / 2;

        return !(thisRight < bLeft ||   
                 thisLeft > bRight ||   
                 thisTop < bBottom ||   
                 thisBottom > bTop);    
    }
    boolean isInside(Rectangle b) {
        double thisLeft = this.coorX - this.width / 2;
        double thisRight = this.coorX + this.width / 2;
        double thisBottom = this.coorY - this.height / 2;
        double thisTop = this.coorY + this.height / 2;

        double bLeft = b.coorX - b.width / 2;
        double bRight = b.coorX + b.width / 2;
        double bBottom = b.coorY - b.height / 2;
        double bTop = b.coorY + b.height / 2;

        return thisLeft >= bLeft && thisRight <= bRight && thisBottom >= bBottom && thisTop <= bTop;
    }
   
}
public class LAB2NO7 {
    public static void main(String[] args){
        Rectangle r1 = new Rectangle();
        System.out.println("Enter r1's center x-,y-coordinate,width,and height: ");
        r1.get();
        Rectangle r2 = new Rectangle();
        System.out.println("Enter r2's center x-,y-coordinate,width,and height: ");
        r2.get();
        if (r2.isInside(r1)) {
            System.out.println("r2 is inside r1");
        } else if (r1.isOverlap(r2)) {
            System.out.println("r2 overlaps with r1");
        } else {
            System.out.println("r2 does not overlap with r1");
        }
    }
}
