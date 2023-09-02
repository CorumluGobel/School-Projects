package OOP_Project;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.Color;
import java.awt.event.ActionEvent;

public class ChildGUI {
	private JTextField answerField;
	private TimerClass timer;
	private transient int i = 0;
	public ChildGUI(ChildAccount child, Admin admin) {
		JFrame frame = new JFrame();
		
		frame.setSize(500, 500);
		frame.getContentPane().setLayout(null);
		
		JButton exerciseChoose = new JButton("Exercise");
		exerciseChoose.setBounds(10, 11, 89, 23);
		frame.getContentPane().add(exerciseChoose);
		
		JLabel questionLabel = new JLabel("");
		questionLabel.setHorizontalAlignment(SwingConstants.CENTER);
		questionLabel.setBounds(10, 115, 252, 49);
		frame.getContentPane().add(questionLabel);
		
		answerField = new JTextField();
		answerField.setHorizontalAlignment(SwingConstants.CENTER);
		answerField.setBounds(296, 122, 95, 35);
		frame.getContentPane().add(answerField);
		answerField.setColumns(10);
		
		JButton submitButton = new JButton("Submit");
		submitButton.setBounds(296, 165, 95, 23);
		frame.getContentPane().add(submitButton);
		
		JLabel questionNumberLabel = new JLabel("");
		questionNumberLabel.setHorizontalAlignment(SwingConstants.CENTER);
		questionNumberLabel.setBounds(10, 90, 252, 14);
		frame.getContentPane().add(questionNumberLabel);
		
		JLabel timerLabel = new JLabel("Seconds Passed: 0");
		timerLabel.setHorizontalAlignment(SwingConstants.CENTER);
		timerLabel.setBounds(221, 40, 170, 14);
		frame.getContentPane().add(timerLabel);
		timerLabel.setVisible(false);
		
		JLabel checkLabel = new JLabel("");
		checkLabel.setHorizontalAlignment(SwingConstants.CENTER);
		checkLabel.setBounds(401, 132, 73, 14);
		frame.getContentPane().add(checkLabel);
		
		JButton backButton = new JButton("Go Back");
		backButton.setBounds(385, 11, 89, 23);
		frame.getContentPane().add(backButton);
		frame.setVisible(true);
		
		exerciseChoose.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				timer = new TimerClass(timerLabel);
				timerLabel.setVisible(true);
				Exercise exercise = new Exercise();
				exercise = child.getExercises();
				questionLabel.setText(exercise.getQuestionList().get(0).getQuestion());
				questionNumberLabel.setText("Question: 1/" + Integer.toString(exercise.getQuestionList().size()));
				if(!submitButton.isVisible()) {
					submitButton.setVisible(true);
					questionNumberLabel.setVisible(true);
					answerField.setVisible(true);
				}
			}
		});
		submitButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Exercise exercise = new Exercise();
				exercise = child.getExercises();
				String answer = answerField.getText();
				answerField.setText(null);
				exercise.getQuestionList().get(i).setUserAnswer(Integer.parseInt(answer));
				exercise.getQuestionList().get(i).setTimeTaken(timer.getSecondsPassedQuestion());
				if(Integer.parseInt(answer) == exercise.getQuestionList().get(i).getCorrectAnswer()) {
					exercise.getQuestionList().get(i).setAnsweredCorrectly(true);
					if(exercise.getQuestionList().get(i).getTimeTaken() > 3)
						exercise.getQuestionList().get(i).setScore(100/exercise.getQuestionList().size()-exercise.getQuestionList().get(i).getTimeTaken());
					else
						exercise.getQuestionList().get(i).setScore(100/exercise.getQuestionList().size());
					checkLabel.setText("Correct");
					checkLabel.setForeground(Color.green);
				}
				else {
					exercise.getQuestionList().get(i).setAnsweredCorrectly(false);
					exercise.getQuestionList().get(i).setScore(0);
					checkLabel.setText("Wrong");
					checkLabel.setForeground(Color.red);
				}
				if(i+1 < exercise.getQuestionList().size()) {
					questionNumberLabel.setText("Question:" + Integer.toString(i+2) + "/" + Integer.toString(child.getExercises().getQuestionList().size()));
					questionLabel.setText(child.getExercises().getQuestionList().get(i+1).getQuestion());
					i++;
				}//soru bittiği zaman cevreye girer
				else {
					timer.stopUpdatingTimer();//zamanlayıcı durdurulur
					exercise.setTimePassed(timer.getSecondsPassed());
					submitButton.setVisible(false);
					questionNumberLabel.setVisible(false);
					answerField.setVisible(false);
					//soruların puanları toplanarak toplam test skoru alınır
					int sum = 0;
					for(int j = 0; j < exercise.getQuestionList().size(); j++) {
						sum += exercise.getQuestionList().get(j).getScore();
					}
					exercise.setFinalScore(sum);
					questionLabel.setText("Final Score: " + Integer.toString(exercise.getFinalScore()));
					String filePath2 = "resources/gunce.xlsx";
					try {
						child.writeExerciseToExcel(child, filePath2);
					} catch (IOException e1) {
						e1.printStackTrace();
					}
				}
					
			}
		});
		backButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new LoginGUI(admin);
			}
		});
		
	}
}
