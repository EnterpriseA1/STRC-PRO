/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab1;

/**
 *
 * @author KKhamvised
 */
public class LAB1NO2 {
    public static void main(String [] args){
        double startMoney = 100.0;
        double interestRate = 1 + 0.00417;
        double previousMonth = 0.00;
        double currentIncome = startMoney;
        double endMonth = 6;
        for (int i = 0; i < endMonth; i++) {
            if (i == 0) {
                currentIncome *= interestRate;
                previousMonth = currentIncome;
            } else {
                currentIncome = (100 + previousMonth) * interestRate;
                previousMonth = currentIncome;
            }
        }
        String formattedCalculation = String.format("%.2f", currentIncome);
        System.out.println(formattedCalculation);
        System.out.println("==============================");
    }
}
