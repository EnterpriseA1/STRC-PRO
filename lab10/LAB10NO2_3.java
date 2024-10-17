package lab10;

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;

public class LAB10NO2_3 extends JPanel implements Runnable {
    private StillClock clock;
    private JLabel timeLabel;
    private Thread animation;
    public LAB10NO2_3(JPanel mainPanel, TimeZone zone) {
        clock = new StillClock(zone);
        timeLabel = new JLabel(clock.getCurrentTime(), SwingConstants.CENTER);
        timeLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        mainPanel.add(clock);
        mainPanel.add(timeLabel);
        animation = new Thread(this);
        animation.start();
    }
      @Override
        public void run() {
             while (true) {
                 clock.setCurrentTime();
                 clock.repaint();
                 timeLabel.setText(clock.getCurrentTime());
                 try {
                     Thread.sleep(1000);
                 } catch (InterruptedException e) {
                     e.printStackTrace();
                 }
             }
        }

    private class TimerListener implements ActionListener {
        @Override 
        public void actionPerformed(ActionEvent e) {
            clock.setCurrentTime();
            clock.repaint();
            timeLabel.setText(clock.getCurrentTime());
        }
    }

    /** Main method */
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setTitle("ClockAnimation");
        frame.setSize(600, 300);
        frame.setLayout(new FlowLayout(FlowLayout.CENTER));

        JPanel JPPanel = new JPanel();
        JPPanel.setLayout(new BoxLayout(JPPanel, BoxLayout.Y_AXIS));
        LAB10NO2_3 JPClock = new LAB10NO2_3(JPPanel, TimeZone.getTimeZone("Asia/Tokyo"));
        JLabel JPLabel = new JLabel("Japan", SwingConstants.CENTER);
        JPLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        JPPanel.add(JPLabel);

        JPanel THPanel = new JPanel();
        THPanel.setLayout(new BoxLayout(THPanel, BoxLayout.Y_AXIS));
        LAB10NO2_3 THClock = new LAB10NO2_3(THPanel, TimeZone.getTimeZone("Asia/Bangkok"));
        JLabel THLabel = new JLabel("Thailand", SwingConstants.CENTER);
        THLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        THPanel.add(THLabel);

        frame.add(JPPanel);
        frame.add(THPanel);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}

class StillClock extends JPanel {
    private int hour;
    private int minute;
    private int second;
    private TimeZone timeZone;

    public StillClock() {
        this(TimeZone.getDefault());
    }

    public StillClock(TimeZone z) {
        this.timeZone = z;
        setCurrentTime();
    }

    public void setCurrentTime() {
        Calendar calendar = new GregorianCalendar(timeZone);
        this.hour = calendar.get(Calendar.HOUR_OF_DAY);
        this.minute = calendar.get(Calendar.MINUTE);
        this.second = calendar.get(Calendar.SECOND);
    }

    public String getCurrentTime() {
        return String.format("%02d:%02d:%02d", hour, minute, second);
    }

    @Override /** Draw the clock */
protected void paintComponent(Graphics g) {
    super.paintComponent(g);

    // Initialize clock parameters
    int clockRadius = (int)(Math.min(getWidth(), getHeight()) * 0.8 * 0.5);
    int xCenter = getWidth() / 2;
    int yCenter = getHeight() / 2;

    // Draw circle
    g.setColor(Color.black);
    g.drawOval(xCenter - clockRadius, yCenter - clockRadius, 2 * clockRadius, 2 * clockRadius);
    g.drawString("12", xCenter - 5, yCenter - clockRadius + 12);
    g.drawString("9", xCenter - clockRadius + 3, yCenter + 5);
    g.drawString("3", xCenter + clockRadius - 10, yCenter + 3);
    g.drawString("6", xCenter - 3, yCenter + clockRadius - 3);

    // Draw second hand
    int sLength = (int)(clockRadius * 0.8);
    int xSecond = (int)(xCenter + sLength * Math.sin(second * (2 * Math.PI / 60)));
    int ySecond = (int)(yCenter - sLength * Math.cos(second * (2 * Math.PI / 60)));
    g.setColor(Color.red);
    g.drawLine(xCenter, yCenter, xSecond, ySecond);

    // Draw minute hand
    int mLength = (int)(clockRadius * 0.65);
    int xMinute = (int)(xCenter + mLength * Math.sin(minute * (2 * Math.PI / 60)));
    int yMinute = (int)(yCenter - mLength * Math.cos(minute * (2 * Math.PI / 60)));
    g.setColor(Color.blue);
    g.drawLine(xCenter, yCenter, xMinute, yMinute);

    // Draw hour hand
    int hLength = (int)(clockRadius * 0.5);
    int xHour = (int)(xCenter + hLength * Math.sin((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
    int yHour = (int)(yCenter - hLength * Math.cos((hour % 12 + minute / 60.0) * (2 * Math.PI / 12)));
    g.setColor(Color.green);
    g.drawLine(xCenter, yCenter, xHour, yHour);
}

    private void drawHand(Graphics g, double value, double length, Color color) {
        int xCenter = getWidth() / 2;
        int yCenter = getHeight() / 2;
        int x = (int) (xCenter + length * Math.sin(value * (2 * Math.PI / 60)));
        int y = (int) (yCenter - length * Math.cos(value * (2 * Math.PI / 60)));
        g.setColor(color);
        g.drawLine(xCenter, yCenter, x, y);
    }

    @Override
    public Dimension getPreferredSize() {
        return new Dimension(200, 200);
    }
}