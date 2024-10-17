/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab9;

/**
 *
 * @author Kkhamwiset
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class getButtonData implements ActionListener {
    private JTextField output;
    private StringBuilder currentInput = new StringBuilder();
    private double previousValue = 0;
    private String currentOperation = "";

    public getButtonData(JTextField output) {
        this.output = output;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton source = (JButton) e.getSource();
        String command = source.getText();

        if ("C".equals(command)) {
            currentInput.setLength(0);
            previousValue = 0;
            currentOperation = "";
            output.setText("");
        } else if ("=".equals(command)) {
            if (currentOperation.isEmpty() || currentInput.length() == 0) {
                return;
            }

            double currentValue = Double.parseDouble(currentInput.toString());
            double result = 0;

            switch (currentOperation) {
                case "+":
                    result = previousValue + currentValue;
                    break;
                case "-":
                    result = previousValue - currentValue;
                    break;
                case "*":
                    result = previousValue * currentValue;
                    break;
                case "/":
                    if (currentValue != 0) {
                        result = previousValue / currentValue;
                    } else {
                        JOptionPane.showMessageDialog(null, "Cannot divide by zero.");
                        return;
                    }
                    break;
            }

            output.setText(String.valueOf(result));
            currentInput.setLength(0);
            previousValue = result;
            currentOperation = "";
        } else if ("√".equals(command) || "x\u00B2".equals(command) || "±".equals(command)) {
            if (currentInput.length() > 0) {
                double currentValue = Double.parseDouble(currentInput.toString());
                double result = 0;

                switch (command) {
                    case "√":
                        result = Math.sqrt(currentValue);
                        break;
                    case "x\u00B2":
                        result = Math.pow(currentValue, 2);
                        break;
                    case "±":
                        result = -currentValue;
                        break;
                }

                output.setText(String.valueOf(result));
                currentInput.setLength(0); 
                previousValue = result;
            }
        } else if ("+".equals(command) || "-".equals(command) || "*".equals(command) || "/".equals(command)) {
            if (currentInput.length() > 0) {
                previousValue = Double.parseDouble(currentInput.toString());
                currentInput.setLength(0);
                output.setText("");
            }

            currentOperation = command;
        } else {
            currentInput.append(command);
            output.setText(currentInput.toString());
        }
    }
}

public class LAB9NO5 {

    public static void main(String[] args) {
        JFrame mainFrame = new JFrame("Calculator");
        mainFrame.setLayout(new BorderLayout());
        JPanel outputPanel = new JPanel();
        JTextField output = new JTextField(20);
        output.setHorizontalAlignment(JTextField.RIGHT);
        output.setEditable(false);
        output.setBackground(Color.WHITE);
        outputPanel.add(output);
        mainFrame.add(outputPanel, BorderLayout.NORTH);

        JPanel buttonField = new JPanel();
        buttonField.setLayout(new GridLayout(5, 4, 0, 0));

        String[][] data = {
            {"√", "x\u00B2", "±", "C"},
            {"7", "8", "9", "+"},
            {"6", "5", "4", "-"},
            {"1", "2", "3", "*"},
            {"0", ".", "=", "/"}
        };

        getButtonData listener = new getButtonData(output);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                JButton button = new JButton(data[i][j]);
                button.addActionListener(listener);
                if ("C".equals(data[i][j])) {
                    button.setForeground(Color.RED);
                }
                buttonField.add(button);
            }
        }

        mainFrame.add(buttonField, BorderLayout.CENTER);
        mainFrame.setSize(250, 250);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setLocationRelativeTo(null);
        mainFrame.setVisible(true);
    }
}
