/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab1;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author KKhamvised
 */
public class LAB1NO9 {
    public static void main (String [] args){
                System.out.print("Please input numbers: ");
        List<Integer> numbers = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        int n;
        boolean loop = true;
        while (loop) {
            n = input.nextInt();
            if (n == 0) {
                loop = false;
            } else {
                numbers.add(n);
            }
        }
        Collections.sort(numbers);
        int maxCount = 1, currentCount = 1;
        int maxNumber = numbers.get(0), currentNumber = numbers.get(0);
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers.get(i).equals(currentNumber)) {
                currentCount++;
            } else {
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                    maxNumber = currentNumber;
                }
                currentNumber = numbers.get(i);
                currentCount = 1;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxNumber = currentNumber;
        }

        System.out.println(maxCount + " " + maxNumber);
        System.out.println("==============================");
    }
}
