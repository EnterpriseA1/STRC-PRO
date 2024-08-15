/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Week1;

import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 *
 * @author Asus
 */
public class Ex1 {

    public static void main(String[] args) {
        String dialog = JOptionPane.showInputDialog(null, "Input Farenheit", "Ex1", JOptionPane.QUESTION_MESSAGE);
        double fh = Double.parseDouble(dialog);
        double c;
        c = (5.0 / 9.0) * (fh - 32);
        JOptionPane.showMessageDialog(null, dialog, "Celsius", JOptionPane.INFORMATION_MESSAGE);
    }
}
