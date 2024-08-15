/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab2;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
class LinearEquation{
    private double a,b,c,d,e,f;
    public double x,y;
    LinearEquation(double a,double b,double c,double d,double e,double f){
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
    }
    public boolean isSolveable(){
        return (a * d) - (b*c) != 0;
    }
    public void getX(){
        double calculation = ((e*d) - (b*f)) / ((a*d) - (b*c));
        this.x = calculation;
    }
    public void getY(){
        double calculation = ((a*f) - (e*c)) / ((a*d) - (b*c));
        this.y = calculation;
    }
}

public class LAB2NO5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double a,b,c,d,e,f;
        Scanner input = new Scanner(System.in);
        a = input.nextDouble();
        b = input.nextDouble();
        c = input.nextDouble();
        d = input.nextDouble();
        e = input.nextDouble();
        f = input.nextDouble();
        LinearEquation shapeOne = new LinearEquation(a,b,c,d,e,f);
        if (shapeOne.isSolveable()){
            shapeOne.getX();
            shapeOne.getY();
            System.out.println("x is " + shapeOne.x + " and y is " + shapeOne.y);
        }
        else{
            System.out.println("The equation has no solution");
        }
    }
    
}
