import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class LAB10NO4 extends JFrame {
    private RaceCar raceCarPanel = new RaceCar();
    private JTextField[] carSpeedFields = new JTextField[4];

    public LAB10NO4() {
        setLayout(new BorderLayout());
        add(raceCarPanel, BorderLayout.CENTER);

        JPanel controlPanel = new JPanel();
        for (int i = 0; i < 4; i++) {
            carSpeedFields[i] = new JTextField("" + (10 * (i + 1)), 3);
            controlPanel.add(new JLabel("Car " + (i + 1) + ":"));
            controlPanel.add(carSpeedFields[i]);
            final int index = i;
            carSpeedFields[i].addActionListener(e -> raceCarPanel.setCarSpeed(index, Integer.parseInt(carSpeedFields[index].getText())));
        }
        add(controlPanel, BorderLayout.NORTH);
    }

    public static void main(String[] args) {
        JFrame frame = new LAB10NO4();
        frame.setTitle("Exercise18_17");
        frame.setSize(400, 250);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

class Car {
    int x, y, speed;

    public Car(int y, int speed) {
        this.x = 0;
        this.y = y;
        this.speed = speed;
    }

    public void move(int panelWidth) {
        x += speed;
        if (x > panelWidth) {
            x = -50;
        }
    }
}

class RaceCar extends JPanel {
    private Car[] cars = new Car[4];
    private Timer timer;

    public RaceCar() {
        for (int i = 0; i < 4; i++) {
            cars[i] = new Car(i * 40 + 10, 10 * (i + 1));
        }
        timer = new Timer(100, e -> {
            for (Car car : cars) {
                car.move(getWidth());
            }
            repaint();
        });
        timer.start();
    }

    public void setCarSpeed(int carIndex, int speed) {
        if (carIndex >= 0 && carIndex < cars.length) {
            cars[carIndex].speed = speed;
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
    
        for (int i = 0; i <= 4; i++) {
            g.drawLine(0, i * 40, getWidth(), i * 40);
        }

        for (Car car : cars) {
            drawCar(g, car);
        }
    }

    private void drawCar(Graphics g, Car car) {
        int xBase = car.x;
        int yBase = car.y + 30;
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
}