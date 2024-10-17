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



public class LAB9NO6  extends JPanel {
    private int xOffset = 0;  
    public void moveLeft() {
        xOffset -= 10; 
        repaint();
    }

    public void moveRight() {
        xOffset += 10; 
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        int baseX = 20 + xOffset;
        int baseY = 220;
        int width = 80;
        int height = 40;
        int radius = 20;

        g.drawArc(baseX, baseY, width, height, 0, 180);
        g.drawLine(baseX + width / 2, baseY, baseX + width / 2, 20);
        g.drawLine(baseX + width / 2, 20, baseX + width / 2 + 100, 20);
        g.drawLine(baseX + width / 2 + 100, 20, baseX + width / 2 + 100, 40);

        g.drawOval(baseX + width / 2 + 100 - radius, 40, 2 * radius, 2 * radius);

        g.drawLine(baseX + width / 2 + 100 - (int) (radius * Math.cos(Math.toRadians(45))),
                   40 + radius + (int) (radius * Math.sin(Math.toRadians(45))),
                   baseX + width / 2 + 100 - 60,
                   40 + radius + 60);
        g.drawLine(baseX + width / 2 + 100 + (int) (radius * Math.cos(Math.toRadians(45))),
                   40 + radius + (int) (radius * Math.sin(Math.toRadians(45))),
                   baseX + width / 2 + 100 + 60,
                   40 + radius + 60);

        g.drawLine(baseX + width / 2 + 100, 40 + 2 * radius,
                   baseX + width / 2 + 100, 40 + radius + 80);

        g.drawLine(baseX + width / 2 + 100, 40 + radius + 80,
                   baseX + width / 2 + 100 - 40, 40 + radius + 80 + 40);
        g.drawLine(baseX + width / 2 + 100, 40 + radius + 80,
                   baseX + width / 2 + 100 + 40, 40 + radius + 80 + 40);
    }
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hangman");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        LAB9NO6  hangmanPanel = new LAB9NO6 ();
        frame.add(hangmanPanel);
        JPanel buttonPanel = new JPanel();
        JButton leftButton = new JButton("Move Left");
        JButton rightButton = new JButton("Move Right");
        leftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                hangmanPanel.moveLeft();
            }
        });

        rightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                hangmanPanel.moveRight();
            }
        });
        buttonPanel.add(leftButton);
        buttonPanel.add(rightButton);
        frame.add(buttonPanel, "South");
        frame.setVisible(true);
    }
}
