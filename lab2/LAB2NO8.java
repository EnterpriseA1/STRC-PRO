/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab2;

/**
 *
 * @author KKhamvised
 */
class RegularPolygon{
    private int n;
    private double side,x,y;
    
    RegularPolygon(){
        this.n = 3;
        this.side = 1;
        this.x = 0;
        this.y = 0;
    }
    RegularPolygon(int n,double side){
        this.n = n;
        this.side = side;
        this.x = 0;
        this.y = 0;
    }
    RegularPolygon(int n,double side,double x,double y){
        this.n = n;
        this.side = side;
        this.x = x;
        this.y = y;
    }
    public void set(int n,double side,double x,double y){
        this.n = n;
        this.side = side;
        this.x = x;
        this.y = y;
    }
    public int getN(){
        return this.n;
    }
    public double getSide(){
        return this.side;
    }
    public double getX(){
        return this.x;
    }
     public double getY(){
        return this.y;
    }
     public void detail(){
         System.out.println(this.toString());
     }
     public double getPerimeter(){
         return this.n * this.side;
     }
     public double getArea(){
      
         return (this.n*(Math.pow(this.side,2)) / (4*Math.tan(Math.PI / this.n)));
     }
     @Override
     public String toString(){
      return "====================================" + '\n' +
      "Number of sides: " + this.n + '\n'+
      "Perimeter of Polygon: " + this.getPerimeter() + '\n'+
      "Area of Polygon: " + this.getArea() + "\n\n";
    }
}
public class LAB2NO8 {
    public static void main(String[] args){
        RegularPolygon poly1 = new RegularPolygon();
        System.out.println("Polygon No.1 : ");
        poly1.detail();
        RegularPolygon poly2 = new RegularPolygon(6,4);
        System.out.println("Polygon No.2 : ");
        poly2.detail();
        RegularPolygon poly3 = new RegularPolygon(10,4,5.6,7.8);
        System.out.println("Polygon No.3 : ");
        poly3.detail();
    }
}
