package w9n6;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.Timer;
public class W9n6 extends JPanel{
    private int xOffset = 0;  
    private int yOffset = 0;
    
    public double r = 0;
    public boolean c = true;
    Timer timer;
    
    public void start() {
        if (timer == null){
            timer =  new Timer(10, e -> {
                     if (c){
                        xOffset += 1;
//                        yOffset += 1;
                        if ((int)(Math.toRadians(r)*10) >= 10){
                            c = false;
                        }
                        r++;
                     }
                     else{
//                         yOffset -= 1;
                         xOffset -= 1;
                            if ((int)(Math.toRadians(r)*10) <= -10){
                                c = true;
                            }
                        r--;
                     }
//                     baseX+=xOffset;
                     repaint();
            });
            timer.start();
        }
        
    }
    
    public void stop() {
        if (timer != null) {
             repaint();
            timer.stop();
            timer = null;// Stop the timer
        }
    }
    
    public int xCal(){
        return (int)(Math.sin(Math.toRadians(r)) * 20);
    }
    
    public int yCal(){
        return (int)(Math.cos(Math.toRadians(r)) * 20);
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int baseX = 20;
        int baseY = 220;
        
        int width = 80;
        int height = 40;
        int radius = 20;
        
        int xCenter = baseX + width / 2 + 100;
        int yCenter = 20;
        
        g.drawArc(baseX, baseY, width, height, 0, 180);
        
        // Draw the vertical part of the pillar
        g.drawLine(baseX + width / 2, baseY, baseX + width / 2, 20);
        
        // Draw the horizontal part of the pillar
        g.drawLine(baseX + width / 2, 20, baseX + width / 2 + 100, 20);
        
        // Draw the end part of the pillar
        g.drawLine(xCenter, yCenter, xCenter + xCal() , yCenter + yCal());
        
        // Draw the head of the hangman
        g.drawOval(xCenter - radius + xCal(), yCenter + yCal(), 2 * radius, 2 * radius);
        
        // Draw the arms
        g.drawLine(xCenter - (int)(radius * Math.cos(Math.toRadians(45))) + (int)(xCal()*Math.cos(Math.toRadians(45))),
                   40 + radius  + (int) (radius * Math.sin(Math.toRadians(45))),
                   xCenter - 60 + (int)(xCal()*Math.cos(Math.toRadians(45))),
                   40 + radius + 60);
        g.drawLine(baseX + width / 2 + 100 + (int) (radius * Math.cos(Math.toRadians(45))) + xOffset,
                   40 + radius + (int) (radius * Math.sin(Math.toRadians(45))),
                   baseX + width / 2 + 100 + 60 + xOffset,
                   40 + radius + 60);
        
        // Draw the body
        g.drawLine(baseX + width / 2 + 100 + (xOffset), 40 + 2 * radius,
                   baseX + width / 2 + 100 + xOffset, 40 + radius + 80);
        
        // Draw the legs
        g.drawLine(baseX + width / 2 + 100 + xOffset, 40 + radius + 80,
                   baseX + width / 2 + 100 - 40 + xOffset, 40 + radius + 80 + 40);
        g.drawLine(baseX + width / 2 + 100 + xOffset, 40 + radius + 80,
                   baseX + width / 2 + 100 + 40 + xOffset, 40 + radius + 80 + 40);
    }
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("Hangman");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        W9n6 hangmanPanel = new W9n6();
        JPanel buttonPanel = new JPanel();
        JButton leftButton = new JButton("Start");
        JButton rightButton = new JButton("Stop");
        leftButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                hangmanPanel.start();
            }
        });

        rightButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                hangmanPanel.stop();
            }
        });
        hangmanPanel.setPreferredSize(new Dimension(400,400));
        buttonPanel.add(leftButton);
        buttonPanel.add(rightButton);
        frame.add(buttonPanel, "North");
        frame.add(hangmanPanel);
        frame.setVisible(true);
        
    }
}
