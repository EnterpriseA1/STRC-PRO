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
public class LAB4NO7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        int[] numbers = new int[n];
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            numbers[i] = scanner.nextInt();
            totalSum += numbers[i];
        }
        
        boolean[] canSum = new boolean[totalSum / 2 + 1];
        canSum[0] = true;
        
        for (int num : numbers) {
            for (int j = totalSum / 2; j >= num; j--) {
                if (canSum[j - num]) {
                    canSum[j] = true;
                }
            }
        }
        int halfSum = totalSum / 2;
        while (!canSum[halfSum]) {
            halfSum--;
        }
        int group1Sum = halfSum;
        int group2Sum = totalSum - group1Sum;
        int minDifference = Math.abs(group1Sum - group2Sum);
        
        System.out.println(minDifference);
        
        scanner.close();
    }
}
