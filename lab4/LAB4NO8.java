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
public class LAB4NO8 {

    public static void main(String[] args) {
        int n, m;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        m = input.nextInt();
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = input.nextInt();
            }
        }
        int maxSum = 0;
        int [] maxIdx = new int[2];
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                int dif = Math.abs(arr[i][j] - arr[i+1][j]);
                int sum_ = arr[i][j] + arr[i+1][j];
                if (dif <= 10 && sum_ > maxSum){
                    maxSum = sum_;
                    maxIdx[0] = i;
                    maxIdx[1] = j;
                }
            }
        }
        for (int x: maxIdx){
            System.out.printf("%d ",x + 1);
        }
        System.out.println("");
    }
}