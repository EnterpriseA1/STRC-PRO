/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab3;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
public class LAB3NO6 {
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
