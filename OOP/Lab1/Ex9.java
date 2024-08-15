/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week1;

import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author Asus
 */
public class Ex9 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] arr = new int[100];
        int i = 0;
        while (true) {
            arr[i] = input.nextInt();
            if (arr[i] == 0) {
                break;
            }
            i++;
        }
        int maxNum = 0;
        int max = 0;
        int count = 1;
        Arrays.sort(arr);
        for (int j = 0; j < 100; j++) {
            if (j == 99) {
                break;
            } else {
                if (arr[j] == arr[j + 1]) {
                    maxNum = arr[j];
                    count++;
                } else {
                    if (count > max) {
                        max = count;
                        maxNum = arr[j];
                    }
                    count = 1;
                }
            }
        }
        System.out.println(maxNum + " " + count);
    }
}
