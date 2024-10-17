package lab11;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class LAB11NO5 extends JFrame {
    public LAB11NO5() {
        add(new RaceCar());
    }

    public static void main(String[] args) {
        LAB11NO5 frame = new LAB11NO5();
        frame.setTitle("Exercise");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(200, 100);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

class RaceCar extends JPanel implements Runnable {
    private int xBase = 0;
    private int delay = 10;
    private Thread animationThread;
    private volatile boolean running = true;

    public RaceCar() {
        this.setFocusable(true);
        this.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_EQUALS) {
                    if (delay > 5)
                        delay -= 5;
                }
                else if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_MINUS)
                    delay += 1;
            }
        });
        animationThread = new Thread(this);
        animationThread.start();
    }

    public void run() {
        while (running) {
            repaint();
            try {
                Thread.sleep(delay);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int yBase = getHeight();
        if (xBase > getWidth())
            xBase = -20;
        else
            xBase += 1;
        g.setColor(Color.BLACK);
        g.fillOval(xBase + 10, yBase - 10, 10, 10);
        g.fillOval(xBase + 30, yBase - 10, 10, 10);
        g.setColor(Color.GREEN);
        g.fillRect(xBase, yBase - 20, 50, 10);
        g.setColor(Color.RED);
        Polygon polygon = new Polygon();
        polygon.addPoint(xBase + 10, yBase - 20);
        polygon.addPoint(xBase + 20, yBase - 30);
        polygon.addPoint(xBase + 30, yBase - 30);
        polygon.addPoint(xBase + 40, yBase - 20);
        g.fillPolygon(polygon);
    }

    public void stopAnimation() {
        running = false;
    }
}