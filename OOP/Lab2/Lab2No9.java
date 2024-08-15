package javaapplication1;

import java.util.Scanner;

public class Lab2No9 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = 0, maxNum = 0;
        boolean state = true, found = false;
        while (state) {
            x = input.nextInt();
            if (x == 0) {
                state = false;
            } else {
                if (isPrime(x)) {
                    found = true;
                    if (x > maxNum) {
                        maxNum = x;
                    }
                }
            }
        }
        if (!found) {
            System.out.println("-1");
        } else {
            System.out.println(maxNum);
        }
    }

    static boolean isPrime(int N) {
        for (int i = 2; i < N; i++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }
}
