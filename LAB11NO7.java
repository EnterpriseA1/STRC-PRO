package lab11;


import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;

public class LAB11NO7 extends JFrame {
    public static void main(String args[]) {
        LAB11NO7 a = new LAB11NO7 ();
        a.setSize(600, 500);
        a.setVisible(true);
        a.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private BalloonPanel paintPanel = new BalloonPanel();

    public LAB11NO7 () {
        setLayout(new BorderLayout());
        add(paintPanel);
        setSize(500, 500);
    }

    class BalloonPanel extends JPanel {
        final static int BALLOON_RADIUS = 10;
        final static int BALL_RADIUS = 5;
        final static int GUN_LENGTH = 25;
        final static int PANEL_WIDTH = 200;
        final static int PANEL_HEIGHT = 100;
        

        private int x_Balloon = (int) (Math.random() * PANEL_WIDTH);
        private int y_Balloon = (int) (Math.random() * PANEL_HEIGHT);
        private int angle = 90;

        private LinkedList<SmallBall> list = new LinkedList<>();

        class SmallBall {
            double length;
            double angle;

            SmallBall(double length, double angle) {
                this.length = length;
                this.angle = angle;
            }
        }

        private final Thread repaintThread;

        public BalloonPanel() {
            setFocusable(true);
            this.addKeyListener(new KeyAdapter() {
                public void keyPressed(KeyEvent e) {
                    if (e.getKeyCode() == KeyEvent.VK_LEFT) {
                        if (angle < 180) angle += 3;
                    } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
                        if (angle > 0) angle -= 3;
                    } else if (e.getKeyCode() == KeyEvent.VK_UP) {
                        SmallBall newBall = new SmallBall(GUN_LENGTH, angle);
                        list.add(newBall);
                        new Thread(new BallMover(newBall)).start(); 
                    }
                }
            });

            repaintThread = new Thread(() -> {
                while (true) {
                    repaint();
                    try {
                        Thread.sleep(10);
                    } catch (InterruptedException e) {}
                }
            });
            repaintThread.start(); 
        }

        boolean hit = false;

        public void paint(Graphics g) {
            super.paintComponent(g);
            int x = (int) (GUN_LENGTH * Math.cos(Math.toRadians(angle)) + getWidth() / 2);
            int y = (int) (getHeight() - GUN_LENGTH * Math.sin(Math.toRadians(angle)));
            g.drawLine(getWidth() / 2, getHeight(), x, y);
            g.drawLine(getWidth() / 2 - 1, getHeight(), x - 1, y);
            g.drawLine(getWidth() / 2 - 2, getHeight(), x - 2, y);
            g.drawLine(getWidth() / 2 + 1, getHeight(), x + 1, y);
            g.drawLine(getWidth() / 2 + 2, getHeight(), x + 2, y);

            if (hit) {
                drawBalloonPieces(g);
                hit = false;
                resetBalloonPosition();
                return;
            }

            g.drawOval(x_Balloon - BALLOON_RADIUS, y_Balloon - BALLOON_RADIUS, 2 * BALLOON_RADIUS, 2 * BALLOON_RADIUS);

            // Use a temporary list to avoid ConcurrentModificationException
            LinkedList<SmallBall> ballsToRemove = new LinkedList<>();

            // Draw small balls
            for (SmallBall ball : list) {
                int xBall = (int) (ball.length * Math.cos(Math.toRadians(ball.angle)) + getWidth() / 2);
                int yBall = (int) (getHeight() - ball.length * Math.sin(Math.toRadians(ball.angle)));

                g.fillOval(xBall - BALL_RADIUS, yBall - BALL_RADIUS, 2 * BALL_RADIUS, 2 * BALL_RADIUS);

                if (overlaps(xBall, yBall, BALL_RADIUS, x_Balloon, y_Balloon, BALLOON_RADIUS)) {
                    ballsToRemove.add(ball);
                    hit = true;
                }

                if (xBall > getWidth() || xBall < 0 || yBall < 0) {
                    ballsToRemove.add(ball);
                }
            }

            list.removeAll(ballsToRemove);
        }

        private void drawBalloonPieces(Graphics g) {
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2 - 5, y_Balloon - BALLOON_RADIUS / 2, BALLOON_RADIUS, BALLOON_RADIUS);
            g.drawOval(x_Balloon + 2 * BALLOON_RADIUS + 5 - BALLOON_RADIUS / 2, y_Balloon - BALLOON_RADIUS / 2, BALLOON_RADIUS, BALLOON_RADIUS);
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2, y_Balloon + 2 * BALLOON_RADIUS + 5 - BALLOON_RADIUS / 2, BALLOON_RADIUS, BALLOON_RADIUS);
            g.drawOval(x_Balloon - BALLOON_RADIUS / 2, y_Balloon - 2 * BALLOON_RADIUS - 5 - BALLOON_RADIUS / 2, BALLOON_RADIUS, BALLOON_RADIUS);
        }

        private void resetBalloonPosition() {
            x_Balloon = (int) (Math.random() * PANEL_WIDTH);
            y_Balloon = (int) (Math.random() * PANEL_HEIGHT);
        }

        class BallMover implements Runnable {
            private SmallBall ball;

            public BallMover(SmallBall ball) {
                this.ball = ball;
            }

            @Override
            public void run() {
                while (ball.length < getHeight() + 100) {
                    ball.length += 5; 
                    try {
                        Thread.sleep(100); 
                    } catch (InterruptedException e) {}
                }
                list.remove(ball); 
            }
        }
    }

    public static boolean overlaps(double x1, double y1, double radius1, double x2, double y2, double radius2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= radius1 + radius2;
    }
}