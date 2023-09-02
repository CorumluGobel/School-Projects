package OOP_Project;

import javax.swing.JLabel;
import javax.swing.Timer;

public class TimerClass {
    private long startTime;
    private long questionStartTime;
    private JLabel timerLabel;
    private Timer guiTimer;

    public TimerClass(JLabel timerLabel) {
        this.timerLabel = timerLabel;
        startTime = System.currentTimeMillis();
        questionStartTime = startTime;
        startUpdatingTimer();
    }

    public int getSecondsPassed() {
        long currentTime = System.currentTimeMillis();
        long elapsedTime = currentTime - startTime;
        return (int) (elapsedTime / 1000);
    }
    public int getSecondsPassedQuestion() {
    	long currentTime = System.currentTimeMillis();
    	long questionElapsedTime = currentTime - questionStartTime;
    	questionStartTime = currentTime;
    	return (int) (questionElapsedTime / 1000);
    }
    private void startUpdatingTimer() {
        guiTimer = new Timer(1000, e -> updateTimerLabel());
        guiTimer.start();
    }

    private void updateTimerLabel() {
        int secondsPassed = getSecondsPassed();
        timerLabel.setText("Seconds Passed: " + Integer.toString(secondsPassed));
    }

    public void stopUpdatingTimer() {
        guiTimer.stop();
    }
}
