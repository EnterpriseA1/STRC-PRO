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
public class LAB4NO_11 {
    public static void main(String[] args) {
        int row,col;
        char[][] oilDeposit;
        Scanner input = new Scanner(System.in);
        row = input.nextInt();
        col = input.nextInt();
        input.nextLine();
        oilDeposit = new char[row][col];
        int rowCounter = 0;
        int charCounter = 0;
        char[] consumeChar = new char[col];
        while (rowCounter < row){
            String oilInput = input.nextLine();
            for (int i = 0 ; i < oilInput.length();i++){
                consumeChar[charCounter++] = oilInput.charAt(i);
                if (charCounter == col){
                    for (int k = 0 ; k < col ;k++){
                        oilDeposit[rowCounter][k] = consumeChar[k]; 
                    }
                    for  (int j = 0 ; j < consumeChar.length;j++){
                        consumeChar[j] = '\u0000';
                    }
                    charCounter = 0;
                    rowCounter++;
                }
            }
        }
        int oilCounter = 0;
        for (int i = 0 ; i < row ;i++){
            for (int j = 0 ; j < col ;j++){
                if (oilDeposit[i][j] == '@'){
                    oilCounter++;
                    oilCheck(row,col,i,j,oilDeposit);
                }
            }
        }
        System.out.println(oilCounter);
        
    }
    public static void oilCheck(int row,int col,int x,int y,char [][] oilDeposit){
        if (x < 0 || y < 0 || x >= row || y >= col || oilDeposit[x][y] != '@'){
            return;
        }
        oilDeposit[x][y] = '*';
        oilCheck(row,col,x+1,y,oilDeposit);
        oilCheck(row,col,x-1,y,oilDeposit);
        oilCheck(row,col,x,y+1,oilDeposit);
        oilCheck(row,col,x,y-1,oilDeposit);
        oilCheck(row,col,x+1,y+1,oilDeposit);
        oilCheck(row,col,x+1,y-1,oilDeposit);
        oilCheck(row,col,x-1,y-1,oilDeposit);
        oilCheck(row,col,x-1,y+1,oilDeposit);
        
    }
}
