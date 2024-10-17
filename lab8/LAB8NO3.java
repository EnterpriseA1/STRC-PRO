/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab8;
import java.awt.*;
import javax.swing.*;
/**
 *
 * @author studentcs
 */
abstract class AbstractDrawFunction extends JPanel {
    /**Polygon to hold the points*/
    private Polygon p = new Polygon();
    /**Default constructor*/
    protected AbstractDrawFunction() {
        drawFunction();
        setBackground(Color.white);
    }
    /**Draw the function*/
    public abstract double f(double x);
    /**Obtain points for x coordinates 100, 101, ..., 300*/
    public void drawFunction() {
        for (int x = -100; x <= 100; x++) {
            p.addPoint(x + 200, 200 - (int) f(x));
        }
    }
    /**Paint the function diagram*/
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        // Draw x axis
        g.drawLine(10, 200, 390, 200);
        // Draw y axis
        g.drawLine(200, 30, 200, 390);
        // Draw arrows on x axis
        g.drawLine(390, 200, 370, 190);
        g.drawLine(390, 200, 370, 210);
        // Draw arrows on y axis
        g.drawLine(200, 30, 190, 50);
        g.drawLine(200, 30, 210, 50);
        // Draw x, y
        g.drawString("X", 370, 170);
        g.drawString("Y", 220, 40);
        // Draw a polygon line by connecting the points in the polygon
        g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
    }
}
class method1 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return x*x;

    }
}
class method2 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*Math.sin(Math.toRadians(x));

    }
}
class method3 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*Math.cos(Math.toRadians(x));

    }
}
class method4 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*Math.tan(Math.toRadians(x));

    }
}
class method5 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*(Math.cos(Math.toRadians(x)) + (5*Math.sin(Math.toRadians(x))));

    }
}
class method6 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*((5*Math.cos(Math.toRadians(x)))+Math.sin(Math.toRadians(x)));

    }
}
class method7 extends AbstractDrawFunction {
    @Override
    public double f(double x){
        return 10.0*(Math.log(Math.toRadians(x)) + (x*x));

    }
}
public class LAB8NO3 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Graphs");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(2, 4)); 
        frame.add(createPanel(new method1(), "x^2"));
        frame.add(createPanel(new method2(), "sin(x)"));
        frame.add(createPanel(new method3(), "cos(x)"));
        frame.add(createPanel(new method4(), "tan(x)"));
        frame.add(createPanel(new method5(), "cos(x) + 5*sin(x)"));
        frame.add(createPanel(new method6(), "5*cos(x) + sin(x)"));
        frame.add(createPanel(new method7(), "log(x) + x^2"));
        frame.setSize(1200, 800);
        frame.setVisible(true);
    }
    public static JPanel createPanel(AbstractDrawFunction function, String title) {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(function, BorderLayout.CENTER);
        panel.setBorder(BorderFactory.createTitledBorder(title));
        panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        return panel;
    }
}