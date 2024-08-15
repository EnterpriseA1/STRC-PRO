package javaapplication1;

import java.util.Scanner;

public class Lab3No5 {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter Roach number and round: ");
        int n = input.nextInt();
        int a = input.nextInt();
        RoachPopulation roach = new RoachPopulation(n);
        for (int i = 0; i < a; i++) {
            roach.waitR();
            roach.spray();
        }
        System.out.println("number of roach = " + roach.getNumRoach());

    }
}

class RoachPopulation {

    private int numRoach;

    RoachPopulation(int n) {
        this.numRoach = n;
    }

    RoachPopulation() {
        this.numRoach = 0;
    }

    void waitR() {
        this.numRoach = this.numRoach * 2;
    }

    void spray() {
        this.numRoach = this.numRoach - (int) ((10.0 / 100) * this.numRoach);
    }

    public int getNumRoach() {
        return this.numRoach;
    }

}
