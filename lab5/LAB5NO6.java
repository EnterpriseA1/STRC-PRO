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
public class LAB5NO6 {
    public static void main(String[] args) {
        int [][] gridTable;
        int row,col;
        Scanner input = new Scanner(System.in);
        col = input.nextInt();
        row = input.nextInt();
        gridTable = new int[row][col];
        for (int i = 0 ; i < row ;i++){
            for (int j = 0 ; j < col; j++){
                gridTable[i][j] = input.nextInt();
            }
        }
        System.out.println((isConsecutiveFour(gridTable) ? 1 : 0));
    }
    public static boolean isConsecutiveFour(int[][] values) {
        int numRows = values.length;
        int numCols = values[0].length;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols - 3; j++) {
                int num = values[i][j];
                if (num == values[i][j + 1] && num == values[i][j + 2] && num == values[i][j + 3]) {
                    return true;
                }
            }
        }
        for (int i = 0; i < numRows - 3; i++) {
            for (int j = 0; j < numCols; j++) {
                int num = values[i][j];
                if (num == values[i + 1][j] && num == values[i + 2][j] && num == values[i + 3][j]) {
                    return true;
                }
            }
        }
        for (int i = 0; i < numRows - 3; i++) {
            for (int j = 0; j < numCols - 3; j++) {
                int num = values[i][j];
                if (num == values[i + 1][j + 1] && num == values[i + 2][j + 2] && num == values[i + 3][j + 3]) {
                    return true;
                }
            }
        }

        for (int i = 0; i < numRows - 3; i++) {
            for (int j = 3; j < numCols; j++) {
                int num = values[i][j];
                if (num == values[i + 1][j - 1] && num == values[i + 2][j - 2] && num == values[i + 3][j - 3]) {
                    return true;
                }
            }
        }

        return false; 
    }
}

