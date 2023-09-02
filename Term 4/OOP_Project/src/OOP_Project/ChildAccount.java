package OOP_Project;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.Serializable;

import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.ss.usermodel.WorkbookFactory;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class ChildAccount implements Serializable{
	private String userName;
	private String password;
	private Exercise exercises;
	private static final long serialVersionUID = 1336783321907333497L;
	
	public ChildAccount(String userName, String password) {
		this.userName = userName;
		this.password = password;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Exercise getExercises() {
		return exercises;
	}

	public void setExercises(Exercise exercises) {
		this.exercises = exercises;
	}
	public void writeExerciseToExcel(ChildAccount child, String filePath) throws IOException {
		Workbook workbook;
        Sheet sheet;

        try {
            workbook = WorkbookFactory.create(new FileInputStream(filePath));
        } catch (IOException e) {
            workbook = new XSSFWorkbook();
        }

        if (workbook.getNumberOfSheets() == 0) {
            sheet = workbook.createSheet("Exercise");
        } else {
            sheet = workbook.getSheetAt(0);
        }

        int lastRow = sheet.getLastRowNum();
        int rowIndex = lastRow + 1;


        
        Row headerRow = sheet.createRow(0);
        headerRow.createCell(0).setCellValue("Child Username");
        headerRow.createCell(1).setCellValue("Date");
        headerRow.createCell(2).setCellValue("Points");
        headerRow.createCell(3).setCellValue("A");
        headerRow.createCell(4).setCellValue("B");
        headerRow.createCell(5).setCellValue("N");

        
        Exercise exercise = new Exercise();
        exercise = child.getExercises();
        Row dataRow = sheet.createRow(rowIndex++);
        dataRow.createCell(0).setCellValue(child.getUserName());
        dataRow.createCell(1).setCellValue(exercise.getStartDate().toString());
        dataRow.createCell(2).setCellValue(exercise.getFinalScore());
        dataRow.createCell(3).setCellValue(exercise.getA());
        dataRow.createCell(4).setCellValue(exercise.getB());
        dataRow.createCell(5).setCellValue(exercise.getN());
        int j = 0;
        for(int i = 0; i < exercise.getQuestionList().size(); i++) {
            dataRow.createCell(j+6).setCellValue(exercise.getQuestionList().get(i).getQuestion());
            dataRow.createCell(j+7).setCellValue(exercise.getQuestionList().get(i).getCorrectAnswer());
            dataRow.createCell(j+8).setCellValue(exercise.getQuestionList().get(i).getUserAnswer());
            dataRow.createCell(j+9).setCellValue(exercise.getQuestionList().get(i).isAnsweredCorrectly());
            dataRow.createCell(j+10).setCellValue(exercise.getQuestionList().get(i).getScore());
            dataRow.createCell(j+11).setCellValue(exercise.getQuestionList().get(i).getTimeTaken() + " sn");
            j += 6;
        }

        for(int columnIndex = 0; columnIndex < 8; columnIndex++) {
            sheet.autoSizeColumn(columnIndex);
        }

        try(FileOutputStream outputStream = new FileOutputStream(filePath)) {
            workbook.write(outputStream);
        } catch(IOException e) {
            e.printStackTrace();
        }
    }
}
