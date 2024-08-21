/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab5;
import java.util.*;
/**
 *
 * @author KKhamvised
 */
public class LAB5NO2 {
    public static void main(String[] args) {
        String inputLine;
        ArrayList <String> str = new ArrayList<>();
        ArrayList <Integer> inx = new ArrayList<>();
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()){
            String caseFlex = in.nextLine();
            if("".equals(caseFlex)){
                break;
            }
            try{
                int number = Integer.parseInt(caseFlex);
                inx.add(number);
            }
            catch(NumberFormatException e){
                str.add(caseFlex);
            }
        }
        Star newStar = new Star(str);
        for (int x : inx){
            if (x == 1){
                newStar.addStar();
            }
            else if (x == 2){
                newStar.removeStar();
            }
        }
    }
}
class Star {
    public ArrayList<String> str;
    Star(ArrayList<String> x) {
        this.str = x;
    }

    public void addStar() {
        for (int i = 0; i < str.size(); i++) {
            str.add(i + 1, "*");
            i++;
        }
        printList();
    }

    public void removeStar() {
        str.removeIf(s -> s.equals("*"));
        printList();
    }

    public void printList() {
        System.out.print("[");
        for (int j = 0; j < str.size(); j++) {
            if (j > 0) {
                System.out.print(", ");
            }
            System.out.print(str.get(j));
        }
        System.out.println("]");
    }
}