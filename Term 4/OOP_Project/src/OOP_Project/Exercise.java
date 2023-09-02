package OOP_Project;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;


public class Exercise implements Serializable{
	private int a;
	private int b;
	private int N;
	private List<Questions> questionList;
    private int timePassed;
    private LocalDateTime startDate;
    private int finalScore;
    private static final long serialVersionUID = 1336783321907333497L;
    
    public Exercise() {
        questionList = new ArrayList<>();
        timePassed = 0;
        startDate = LocalDateTime.now();
        finalScore = 0;
    }
    
    public void addQuestion(String questionText, int correctAnswer) {
        Questions question = new Questions(questionText, correctAnswer, 0);
        questionList.add(question);
    }
    
    public List<Questions> getQuestionList() {
		return questionList;
	}

	public void setQuestionList(List<Questions> questionList) {
		this.questionList = questionList;
	}
	
	public int getFinalScore() {
		return finalScore;
	}

	public void setFinalScore(int finalScore) {
		this.finalScore = finalScore;
	}
	
	public int getTimePassed() {
		return timePassed;
	}

	public void setTimePassed(int timePassed) {
		this.timePassed = timePassed;
	}
	
	public LocalDateTime getStartDate() {
		return startDate;
	}

	public void setStartDate(LocalDateTime startDate) {
		this.startDate = startDate;
	}

	public int getA() {
		return a;
	}

	public void setA(int a) {
		this.a = a;
	}

	public int getB() {
		return b;
	}

	public void setB(int b) {
		this.b = b;
	}

	public int getN() {
		return N;
	}

	public void setN(int n) {
		N = n;
	}

	
}
