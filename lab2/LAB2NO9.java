/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab2;
import java.util.Scanner;
/**
 *
 * @author KKhamvised
 */
public class LAB2NO9 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int x = 0,maxNum = 0;
        boolean d = true,found = false;
        while (d){
            x = input.nextInt();
            if (x == 0){
               d = false;
            }
            else{
                if(isPrime(x)){
                    found = true;
                    if (x > maxNum){
                        maxNum = x;
                    }
                   
                }
                
            }
        }
        if (!found){
            System.out.println("-1");
        }
        else{
             System.out.println(maxNum);
        }
    }
    static boolean isPrime(int N){
        for (int i = 2; i < N ; i++){
            if (N % i == 0){
                return false;
            }
        }
        return true;
    }
}
