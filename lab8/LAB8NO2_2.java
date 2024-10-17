/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;

/**
 *
 * @author Kkhamwiset
 */
class House implements Cloneable, Comparable<House> {
    private int id;
    private double area;
    private java.util.Date whenBuilt;

    public House(int id, double area) {
        this.id = id;
        this.area = area;
        whenBuilt = new java.util.Date();
    }

    public int getId() {
        return id;
    }

    public double getArea() {
        return area;
    }

    public java.util.Date getWhenBuilt() {
        return whenBuilt;
    }

    @Override
    public Object clone() {
        try {
            return super.clone();
        }
        catch (CloneNotSupportedException ex) {
            return null;
        }
    }

    @Override
    public int compareTo(House o) {
        if (area > o.area)
            return 1;
        else if (area < o.area)
            return -1;
        else
            return 0;
    }
}
public class LAB8NO2_2 {
     public static void main(String[] args) {
        House house1 = new House(1, 1750.50);
        House house2 = (House)house1.clone();
        System.out.println("house1 ID: " + house1.getId());
        System.out.println("house1 Area: " + house1.getArea());
        System.out.println("house1 Built Date: " + house1.getWhenBuilt());

        System.out.println("\nhouse2 ID: " + house2.getId());
        System.out.println("house2 Area: " + house2.getArea());
        System.out.println("house2 Built Date: " + house2.getWhenBuilt());

        System.out.println("\nAre house1 and house2 the same object? " + (house1 == house2));
        System.out.println("Do house1 and house2 have the same area? " + (house1.compareTo(house2) == 0));
    }
}
