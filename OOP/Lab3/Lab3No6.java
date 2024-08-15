package javaapplication1;

import java.util.Scanner;

public class Lab3No6 {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String s, sf;
        s = input.nextLine();
        sf = s.replaceAll("[^a-zA-Z0-9]", "");
        sf = sf.replace(" ", "");
        if (isPalindrome(sf)) {
            System.out.println(1);
        } else {
            System.out.println(0);
        }

    }

    static boolean isPalindrome(String s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                return false;
            }

        }
        return true;
    }
}
