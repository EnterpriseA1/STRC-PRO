import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.util.Random;

public class LAB9NO8 extends JFrame {
    private JPanel gamePanel;
    private JTextField scoreField, birdYField, speedField, angleField;
    private JButton okButton;
    private Bird bird;
    private Pig pig;
    private int score = 0;
    private Timer animationTimer;
    private double time = 0;
    private double initialSpeed;
    private double launchAngle;
    private BufferedImage backgroundImage;
    private BufferedImage birdImage;
    private BufferedImage pigImage;
    private int birdWidth = 40, birdHeight = 40, pigWidth = 50, pigHeight = 50;

    public LAB9NO8() {
        setTitle("Angry Birds Clone");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        loadImages();

        JPanel topPanel = new JPanel(new FlowLayout());
        topPanel.add(new JLabel("SCENE 1: At Tokyo"));
        topPanel.add(new JLabel("SCORE:"));
        scoreField = new JTextField(5);
        scoreField.setEditable(false);
        topPanel.add(scoreField);
        add(topPanel, BorderLayout.NORTH);

        gamePanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                if (backgroundImage != null) {
                    g.drawImage(backgroundImage, 0, 0, getWidth(), getHeight(), this);
                }
                if (bird != null) bird.draw(g);
                if (pig != null) pig.draw(g);
            }
        };
        gamePanel.setPreferredSize(new Dimension(800, 400));
        add(gamePanel, BorderLayout.CENTER);

        JPanel bottomPanel = new JPanel(new GridLayout(4, 2));
        bottomPanel.add(new JLabel("Bird Position in y-axis:"));
        birdYField = new JTextField("200", 5);
        bottomPanel.add(birdYField);
        bottomPanel.add(new JLabel("Shooting speed:"));
        speedField = new JTextField("50", 5);
        bottomPanel.add(speedField);
        bottomPanel.add(new JLabel("Angle:"));
        angleField = new JTextField("45", 5);
        bottomPanel.add(angleField);
        okButton = new JButton("OK");
        bottomPanel.add(okButton);
        add(bottomPanel, BorderLayout.SOUTH);

        bird = new Bird(50, 200);
        pig = new Pig(new Random().nextInt(300) + 450, new Random().nextInt(200) + 100);

        okButton.addActionListener(e -> launchBird());

        setVisible(true);
    }

    private void loadImages() {
        try {
            backgroundImage = ImageIO.read(new File("src/lab9/Photo/360_F_83452854_Epa5N806VaHrsnr5oBhUYVSEIqWqJGfO.jpg"));
            birdImage = ImageIO.read(new File("src/lab9/Photo/bird.png"));
            pigImage = ImageIO.read(new File("src/lab9/Photo/pig.png"));
            
            // Resize images
            birdImage = resizeImage(birdImage, birdWidth, birdHeight);
            pigImage = resizeImage(pigImage, pigWidth, pigHeight);
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading images: " + e.getMessage());
        }
    }

    private BufferedImage resizeImage(BufferedImage originalImage, int width, int height) {
        BufferedImage resizedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
        Graphics2D g = resizedImage.createGraphics();
        g.drawImage(originalImage, 0, 0, width, height, null);
        g.dispose();
        return resizedImage;
    }

    private void launchBird() {
        try {
            int birdY = Integer.parseInt(birdYField.getText());
            initialSpeed = Double.parseDouble(speedField.getText());
            launchAngle = Math.toRadians(Double.parseDouble(angleField.getText()));

            bird.setY(birdY);
            bird.setX(50);
            time = 0;

            if (animationTimer != null && animationTimer.isRunning()) {
                animationTimer.stop();
            }

            animationTimer = new Timer(16, e -> updateBirdPosition());
            animationTimer.start();

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter valid numbers.");
        }
    }

    private void updateBirdPosition() {
        time += 0.016;
        double x = 50 + initialSpeed * Math.cos(launchAngle) * time;
        double y = bird.getInitialY() - (initialSpeed * Math.sin(launchAngle) * time - 4.9 * time * time);

        bird.setX((int) x);
        bird.setY((int) y);

        if (checkCollision()) {
            animationTimer.stop();
            handleCollision();
        } else if (x >= gamePanel.getWidth() || x < 0 || y > gamePanel.getHeight()) {
            animationTimer.stop();
            JOptionPane.showMessageDialog(this, "Miss! Try again.");
        }

        gamePanel.repaint();
    }

    private boolean checkCollision() {
        int birdX = bird.getX();
        int birdY = bird.getY();
        if (birdY < 0) {
            birdY = 0;
        }
        Rectangle birdRect = new Rectangle(bird.getX(), bird.getY(), birdWidth, birdHeight);
        Rectangle pigRect = new Rectangle(pig.getX(), pig.getY(), pigWidth, pigHeight);
        return birdRect.intersects(pigRect);
    }

    private void handleCollision() {
        score += 100;
        scoreField.setText(String.valueOf(score));
        JOptionPane.showMessageDialog(this, "Hit! Score: " + score);
        resetGame();
    }

    private void resetGame() {
        bird.setX(50);
        bird.setY(bird.getInitialY());
        pig.setX(new Random().nextInt(300) + 450);
        pig.setY(new Random().nextInt(200) + 100);
        gamePanel.repaint();
    }

    class Bird {
        private int x, y, initialY;
        public Bird(int x, int y) {
            this.x = x;
            this.y = y;
            this.initialY = y;
        }
        public void draw(Graphics g) {
            if (birdImage != null) {
                if (y < gamePanel.getHeight() && y > -birdHeight) {
                    g.drawImage(birdImage, x, y, null);
                }
            }
        }
        public void setY(int y) { this.y = y; this.initialY = y; }
        public void setX(int x) { this.x = x; }
        public int getX() { return x; }
        public int getY() { return y; }
        public int getInitialY() { return initialY; }
    }

    class Pig {
        private int x, y;
        public Pig(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public void draw(Graphics g) {
            if (pigImage != null) {
                g.drawImage(pigImage, x, y, null);
            }
        }
        public int getX() { return x; }
        public int getY() { return y; }
        public void setX(int x) { this.x = x; }
        public void setY(int y) { this.y = y; }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LAB9NO8());
    }
}