package lab9;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class LAB9NO4 extends JFrame {
    LAB9NO4(){
 
        setLayout(new BorderLayout());
        JPanel mainPanel = new JPanel(new GridLayout(2, 2, 5, 5));
        JLabel usLabel = new JLabel("    US Dollars");
        JLabel cndLabel = new JLabel("    Canadian Dollars");
        JTextField usField = new JTextField(40);
        JTextField cndField = new JTextField(40);
        cndField.setEnabled(false);
        mainPanel.add(usLabel);
        mainPanel.add(usField);
        mainPanel.add(cndLabel);
        mainPanel.add(cndField);
        add(mainPanel, BorderLayout.CENTER);
        JPanel conPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        JButton conButton = new JButton("Convert");
        conPanel.add(conButton);
        conButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double usDollars = Double.parseDouble(usField.getText());
                    double conversionRate = 1.36;
                    double canadianDollars = usDollars * conversionRate;
                    cndField.setText(String.format("%.2f", canadianDollars));
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Please enter a valid number.");
                }
            }
        });
        add(conPanel, BorderLayout.SOUTH);
        setTitle("Convert US Dollars to Canadian Dollars");
        setSize(400, 175);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    

    public static void main(String[] args) {
        new LAB9NO4();
    }
}