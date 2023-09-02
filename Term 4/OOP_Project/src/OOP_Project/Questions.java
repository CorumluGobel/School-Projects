package OOP_Project;

import java.io.Serializable;

public class Questions implements Serializable{
	private String question;
	private int timeTaken;
	private int userAnswer;
	private int correctAnswer;
	private boolean answeredCorrectly;
	private int score;
	private static final long serialVersionUID = 1336783321907333497L;
	
	public Questions(String question, int correctAnswer, int timeTaken) {
		this.question = question;
		this.timeTaken = timeTaken;
		this.correctAnswer = correctAnswer;
	}
	public String getQuestion() {
		return question;
	}
	public void setQuestion(String question) {
		this.question = question;
	}
	public int getTimeTaken() {
		return timeTaken;
	}
	public void setTimeTaken(int timeTaken) {
		this.timeTaken = timeTaken;
	}
	public int getUserAnswer() {
		return userAnswer;
	}
	public void setUserAnswer(int userAnswer) {
		this.userAnswer = userAnswer;
	}
	public boolean isAnsweredCorrectly() {
		return answeredCorrectly;
	}
	public void setAnsweredCorrectly(boolean answeredCorrectly) {
		this.answeredCorrectly = answeredCorrectly;
	}
	public int getCorrectAnswer() {
		return correctAnswer;
	}
	public void setCorrectAnswer(int correctAnswer) {
		this.correctAnswer = correctAnswer;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
	
}
