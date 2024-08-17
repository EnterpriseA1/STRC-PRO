/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab4;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
public class LAB4NO6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        double distance = 0;
        double[][] pairCoor = new double[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j >= 0; j--) {
                pairCoor[i][j] = input.nextDouble();
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double cal = Math.sqrt(Math.pow(pairCoor[j][0] - pairCoor[k][0], 2) + Math.pow(pairCoor[j][1] - pairCoor[k][1], 2));
//                System.out.printf("Pair %d and Pair %d : %.2f\n",j + 1,k + 1,cal);
                if (j == 0 && k == 1) {
                    distance = cal;
             
                } else {
                    if (cal < distance) {
                        distance = cal;
                    }
                }
            }
        }
        System.out.printf("%.2f\n", distance);
    }
}
