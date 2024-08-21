/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
public class LAB5NO4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        int K = scanner.nextInt();
      
        int[][] matrix = new int[M][N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
        int maxSum = Integer.MIN_VALUE;
        
        for (int i = 0; i <= M - K; i++) {
            for (int j = 0; j <= N - K; j++) {
                int currentSum = 0;
                for (int x = i; x < i + K; x++) {
                    for (int y = j; y < j + K; y++) {
                        currentSum += matrix[x][y];
                    }
                }
                
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }
        System.out.println(maxSum);
    }
}
    