/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab5;
import java.util.*;
/**
 *
 * @author KKhamvised
 */
public class LAB5NO1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        int counter = 0;
        while (counter < 50){
            int x = in.nextInt();
            list.add(x);
            counter++;
        }
        int max_ = 0,min = list.get(0);
        double avg = 0;
        for (int a : list){
            avg += a;
            if (a > max_){
                max_ = a;
            }
            if (a < min){
                min = a;
            }
        }
        System.out.printf("%.2f\n%d\n%d\n",avg/list.size(),max_,min);
        for (int i = 0 ; i < list.size();i++){
            if (list.get(i) % 2 == 0){
                list.remove(i);
                i--;
            }
        }
        for (int y : list){
            System.out.printf("%d ",y);
        }
        System.out.println("");
    }
    
}
