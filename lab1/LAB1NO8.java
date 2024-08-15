/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab1;
import java.util.Scanner;

/**
 *
 * @author KKhamvised
 */
public class LAB1NO8 {
    public static void main (String[] args){
        System.out.print("Please input n, a0 and a1: ");
        Scanner input = new Scanner(System.in);
        int a0,a1,n,prev,prev_2;
        n = input.nextInt();
        a0 = input.nextInt();
        a1 = input.nextInt();
        prev_2 = a0;
        prev = a1;
        System.out.print(prev_2 + " " + prev+" ");
        for (int i = 2 ; i <= n;i++){
            int result = (int)(Math.pow(i,2)*prev - prev_2 + Math.pow(3,i));
            prev_2 = prev;
            prev = result;
            System.out.print(result + " ");
        }
        System.out.println("\n==============================");
    }
}
