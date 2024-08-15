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
public class LAB1NO7 {
    public static void main(String[] args){
        System.out.print("Please input x, n: ");
        Scanner input = new Scanner(System.in);
        int x,n,sum = 0;
        x = input.nextInt();
        n = input.nextInt();
        
        for (int i = 0; i <= n;i++){
            sum += Math.pow(x,i);
        }
        System.out.println(sum);
    }
}
