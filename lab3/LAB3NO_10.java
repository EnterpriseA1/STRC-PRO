/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab3;

import java.util.Scanner;

/**
 *
 * @author KKhamvised
 */
public class LAB3NO_10 {
    public static void main(String[] args){
        int[] light = new int[100];
        int[] start = new int[100];
        int[] end = new int[100];
        int shipCount,lightCount;
        Scanner input = new Scanner(System.in);
        shipCount = input.nextInt();
        lightCount = input.nextInt();
        for (int i = 0 ; i < shipCount; i++){
            start[i] = input.nextInt();
            end[i] = input.nextInt();
        }
        for (int i = 0 ; i < lightCount ; i++){
            int lightFlow = input.nextInt();
            light[lightFlow - 1]++;
        }
        int countShip = 0;
        int k = 0;
        while (k < shipCount){
            for (int i = start[k] + 1 ; i < end[k] - 1;i++){
                if (light[i] == 1){
                    countShip++;
                }
            }
            k++;
        }
        System.out.println(countShip);
    }
}
