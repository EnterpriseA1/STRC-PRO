/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab1;
import javax.swing.JOptionPane;
/**
 *
 * @author KKhamvised
 */
public class LAB1NO1 {

    /**
     * @param args the command line arguments
     */
  public static void main(String[] args) {
  System.out.println("Enter Fahrenheit: ");
//        Scanner input = new Scanner(System.in);
//        double fah = input.nextDouble();
//        double calculation = (5.0 / 9.0) * (fah - 32.0);
//        String formattedCalculation = String.format("%.2f", calculation);
//        System.out.println(formattedCalculation);
        String input = JOptionPane.showInputDialog(null, "Enter temperature in Fahrenheit:", "Input Dialog", JOptionPane.QUESTION_MESSAGE);
        double inputCast = Double.parseDouble(input);
        double calculation = (5.0 / 9.0) * (inputCast - 32.0);
        String formattedCalculation = String.format("%.2f", calculation);
        JOptionPane.showMessageDialog(null, "Temperature in Celsius: " + formattedCalculation, "Fahrenheit to Celsius", JOptionPane.INFORMATION_MESSAGE);
    }
    
}
