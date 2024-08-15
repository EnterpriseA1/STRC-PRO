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
public class LAB4NO5 {
     public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        MatrixMultiplication Mat = new MatrixMultiplication();
        int row = input.nextInt();
        int col = input.nextInt();
        Mat.setMatAsize(row, col);
        int[][] matA = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matA[i][j] = input.nextInt();
            }
        }

        row = input.nextInt();
        col = input.nextInt();
        Mat.setMatBsize(row, col);
        int[][] matB = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                matB[i][j] = input.nextInt();
            }
        }
        Mat.setMat(matA, matB);
        Mat.mult();
    }

}

class MatrixMultiplication {

    int rowA, colA;
    int rowB, colB;
    int[][] matA;
    int[][] matB;

    public MatrixMultiplication() {
    }

    public void setMat(int[][] a, int[][] b) {
        this.matA = a;
        this.matB = b;
    }

    public void setMatAsize(int row, int col) {
        this.rowA = row;
        this.colA = col;
    }

    public void setMatBsize(int row, int col) {
        this.rowB = row;
        this.colB = col;
    }

    public void mult() {
        int[][] output = new int[rowA][colB];
        int temp = 0;
        if (isSolvable()) {

            for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < colB; j++) {
                    output[i][j] = 0;
                    for (int k = 0; k < rowB; k++) {
                        temp += matA[i][k] * matB[k][j];
                        output[i][j] = temp;
                    }
                    temp = 0;
                }
            }
            for (int i = 0; i < rowA; i++) {
                for (int j = 0; j < colB; j++) {
                    System.out.print(output[i][j] + " ");
                }
                System.out.println("");
            }
        } else {
            System.out.println("not solvable");
        }

    }

    public boolean isSolvable() {
        return colA == rowB;
    }
}
