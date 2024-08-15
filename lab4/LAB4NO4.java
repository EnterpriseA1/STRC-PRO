/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab4;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */

class AscendSortFreq {
    public double[] A;
    int arrSize,uniqueSize = 0;

    AscendSortFreq(int n) {
        this.A = new double[n];
        this.arrSize = n;
    }

    public void getElements() {
        Scanner input = new Scanner(System.in);
        for (int i = 0; i < arrSize; i++) {
            A[i] = input.nextDouble();
        }
    }

    public double[] AscendSort() {
        double[] temp = new double[arrSize];
        for (int i = 0; i < arrSize; i++) {
            temp[i] = A[i];
        }
        for (int i = 0; i < temp.length; i++) {
            for (int j = i + 1; j < temp.length; j++) {
                if (temp[j] < temp[i]) {
                    double tempDouble = temp[j];
                    temp[j] = temp[i];
                    temp[i] = tempDouble;
                }
            }
        }
        this.A = temp;
        int newSize = 0;
        double[] B = new double[arrSize];
        for (int i = 0; i < arrSize; i++) {
            if (i == 0 || temp[i] != temp[i - 1]) {
                B[newSize++] = temp[i];
            }
        }
        this.uniqueSize = newSize;
        double[] result = new double[newSize];
        for (int i = 0; i < newSize; i++) {
            result[i] = B[i];
        }
        return result;
    }
    public double[] SortCommuFreq(double[ ]B){
        double[] C = new double[B.length];
        int ptr = 0;
        C[ptr] = 1;
        for (int i = 1 ; i  < arrSize;i++){
            if (A[i] == A[i - 1]){
                    C[ptr]++;
            }
            else{
                C[++ptr] = C[ptr - 1] + 1;
            }
        }
        return C;
    }
}

public class LAB4NO4 {

    public static void main(String[] args) {
        int n;
        System.out.print("Enter number of elements: ");
        Scanner x = new Scanner(System.in);
        n = x.nextInt();
        AscendSortFreq arr = new AscendSortFreq(n);
        arr.getElements();
        double[] result = arr.AscendSort();
        for (double xi : result) {
            System.out.print(xi + " ");
        }
        System.out.println("");
        double[] freq = arr.SortCommuFreq(result);
        for (double xi : freq) {
            System.out.print(xi + " ");
        }
        System.out.println("");
    }
}
