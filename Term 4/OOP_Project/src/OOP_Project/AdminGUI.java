package OOP_Project;

import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.awt.event.ActionEvent;
import javax.swing.table.DefaultTableModel;

import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

public class AdminGUI{
	private JTextField textFieldA;
	private JTextField textFieldB;
	private JTextField textFieldN;
	private JTextField newUserName;
	private JPasswordField newPassword;
	private JTable table;
	private JTextField searchFieldA;
	private JTextField searchFieldB;
	private JTextField searchFieldN;
	public AdminGUI(Admin admin) {
		JFrame frame = new JFrame();
		frame.setSize(500, 500);
		frame.getContentPane().setLayout(new BorderLayout(0, 0));
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		frame.getContentPane().add(tabbedPane, BorderLayout.CENTER);
		
		JPanel settingsPanel = new JPanel();
		tabbedPane.addTab("Settings", null, settingsPanel, null);
		settingsPanel.setLayout(null);
		
		JLabel aLabel = new JLabel("A");
		aLabel.setBounds(10, 50, 15, 14);
		settingsPanel.add(aLabel);
		
		JLabel bLabel = new JLabel("B");
		bLabel.setBounds(10, 100, 15, 14);
		settingsPanel.add(bLabel);
		
		JLabel NLabel = new JLabel("N");
		NLabel.setBounds(10, 150, 15, 14);
		settingsPanel.add(NLabel);
		
		textFieldA = new JTextField();
		textFieldA.setBounds(20, 47, 86, 20);
		settingsPanel.add(textFieldA);
		textFieldA.setColumns(10);
		
		textFieldB = new JTextField();
		textFieldB.setBounds(20, 97, 86, 20);
		settingsPanel.add(textFieldB);
		textFieldB.setColumns(10);
		
		textFieldN = new JTextField();
		textFieldN.setBounds(20, 147, 86, 20);
		settingsPanel.add(textFieldN);
		textFieldN.setColumns(10);
		
		JButton newUser = new JButton("New User");
		newUser.setBounds(372, 146, 100, 23);
		settingsPanel.add(newUser);
		
		newUserName = new JTextField();
		newUserName.setBounds(372, 47, 97, 20);
		settingsPanel.add(newUserName);
		newUserName.setColumns(10);
		
		newPassword = new JPasswordField();
		newPassword.setBounds(372, 97, 97, 20);
		settingsPanel.add(newPassword);
		newPassword.setColumns(10);
		
		JLabel userNameLabel = new JLabel("Username");
		userNameLabel.setHorizontalAlignment(SwingConstants.CENTER);
		userNameLabel.setBounds(299, 50, 63, 14);
		settingsPanel.add(userNameLabel);
		
		JLabel passwordLabel = new JLabel("Password");
		passwordLabel.setHorizontalAlignment(SwingConstants.CENTER);
		passwordLabel.setBounds(299, 100, 63, 14);
		settingsPanel.add(passwordLabel);
		
		JButton delUser = new JButton("Delete User");
		delUser.setBounds(372, 180, 100, 23);
		settingsPanel.add(delUser);
		
		JButton backButton = new JButton("Go Back");
		backButton.setBounds(372, 13, 100, 23);
		settingsPanel.add(backButton);
		
		JPanel statisticsPanel = new JPanel();
		tabbedPane.addTab("Statistics", null, statisticsPanel, null);
		statisticsPanel.setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 50, 459, 105);
		statisticsPanel.add(scrollPane);
		
		table = new JTable();
		scrollPane.setViewportView(table);
		table.setModel(new DefaultTableModel(
			new Object[][] {
			},
			new String[] {
				"Name", "Score", "Time"
			}
		));
		
		JLabel scoreLabel = new JLabel("High Scores");
		scoreLabel.setHorizontalAlignment(SwingConstants.CENTER);
		scoreLabel.setBounds(180, 25, 110, 14);
		statisticsPanel.add(scoreLabel);
		
		searchFieldA = new JTextField();
		searchFieldA.setBounds(44, 196, 86, 20);
		statisticsPanel.add(searchFieldA);
		searchFieldA.setColumns(10);
		
		searchFieldB = new JTextField();
		searchFieldB.setBounds(193, 196, 86, 20);
		statisticsPanel.add(searchFieldB);
		searchFieldB.setColumns(10);
		
		searchFieldN = new JTextField();
		searchFieldN.setBounds(344, 196, 86, 20);
		statisticsPanel.add(searchFieldN);
		searchFieldN.setColumns(10);
		
		JButton searchButton = new JButton("Search");
		searchButton.setBounds(193, 223, 89, 23);
		statisticsPanel.add(searchButton);
		
		JLabel searchLabelA = new JLabel("A");
		searchLabelA.setHorizontalAlignment(SwingConstants.CENTER);
		searchLabelA.setBounds(64, 172, 46, 14);
		statisticsPanel.add(searchLabelA);
		
		JLabel searchLabelB = new JLabel("B");
		searchLabelB.setHorizontalAlignment(SwingConstants.CENTER);
		searchLabelB.setBounds(215, 172, 46, 14);
		statisticsPanel.add(searchLabelB);
		
		JLabel searchLabelN = new JLabel("N");
		searchLabelN.setHorizontalAlignment(SwingConstants.CENTER);
		searchLabelN.setBounds(363, 172, 46, 14);
		statisticsPanel.add(searchLabelN);
		
		JButton backButton2 = new JButton("Go Back");
		backButton2.setBounds(380, 11, 89, 23);
		statisticsPanel.add(backButton2);
		
		List<JButton> buttonList = new ArrayList<JButton>();
		for(int i = 0; i < admin.getConectedAccounts().size(); i++) {
			JButton userButton = new JButton(admin.getConectedAccounts().get(i).getUserName());
			userButton.setBounds(20, 197+(i*50), 86, 20);
			settingsPanel.add(userButton);
			buttonList.add(userButton);
		}
		
		newUser.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String filePath = "resources/users.ser";
				ChildAccount child = new ChildAccount(newUserName.getText(), newPassword.getText());
				admin.getConectedAccounts().add(child);
				try (ObjectOutputStream objOut = new ObjectOutputStream(new FileOutputStream(filePath))) {
		            objOut.writeObject(admin);
		        } catch (IOException e2) {
		            e2.printStackTrace();
		        }
			}
		});
		delUser.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String filePath = "resources/users.ser";
				for(int i = 0; i < admin.getConectedAccounts().size(); i++) {
					if(admin.getConectedAccounts().get(i).getUserName().equals(newUserName.getText()) && admin.getConectedAccounts().get(i).getPassword().equals(newPassword.getText())) {
						admin.getConectedAccounts().remove(i);
					}
				}
				try (ObjectOutputStream objOut = new ObjectOutputStream(new FileOutputStream(filePath))) {
		            objOut.writeObject(admin);
		        } catch (IOException e2) {
		            e2.printStackTrace();
		        }
			}
		});
		searchButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int a = Integer.parseInt(searchFieldA.getText());
		        int b = Integer.parseInt(searchFieldB.getText());
		        int N = Integer.parseInt(searchFieldN.getText());
		        searchFieldA.setText(null);
		        searchFieldB.setText(null);
		        searchFieldN.setText(null);
		        searchExcelScores(a, b, N);
		        for(int i = 0; i < table.getRowCount(); i++) {
		        	if(i < 5) {
		        		JProgressBar progressBar = new JProgressBar();
			        	progressBar.setOrientation(SwingConstants.VERTICAL);
			        	progressBar.setValue((int)table.getModel().getValueAt(i, 1));
			        	progressBar.setBounds(60+(i*80), 300, 40, 100);
			        	statisticsPanel.add(progressBar);
			        	JLabel barLabel = new JLabel((String)table.getModel().getValueAt(i, 0));
			        	barLabel.setBounds(60+(i*80), 400, 40, 14);
			        	barLabel.setHorizontalAlignment(SwingConstants.CENTER);
			        	statisticsPanel.add(barLabel);
			        	JLabel scoreLabel = new JLabel(Integer.toString((int)table.getModel().getValueAt(i, 1)));
			        	scoreLabel.setBounds(60+(i*80), 280, 40, 14);
			        	scoreLabel.setHorizontalAlignment(SwingConstants.CENTER);
			        	statisticsPanel.add(scoreLabel);
		        	}
		        }
		        statisticsPanel.repaint();
			}
		});
		for(int i = 0; i < admin.getConectedAccounts().size(); i++) {
			buttonList.get(i).addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					//assign question
					int index = buttonList.indexOf(e.getSource());
					String filePath = "resources/users.ser";
					Random r = new Random();
					Exercise exercise = new Exercise();
					String s1, s2;
					int a = Integer.parseInt(textFieldA.getText());
					int b = Integer.parseInt(textFieldB.getText());
					int N = Integer.parseInt(textFieldN.getText());
					exercise.setA(a);
					exercise.setB(b);
					exercise.setN(N);
					for(int i = 0; i < N; i++) {
						int randx = r.nextInt(a) + 1;
						int randy = r.nextInt(b) + 1;
						s1 = Integer.toString(randx);
						s2 = Integer.toString(randy);
						exercise.addQuestion(s1 + "x" + s2, randx*randy);
					}
					admin.getConectedAccounts().get(index).setExercises(exercise);
					try (ObjectOutputStream objOut = new ObjectOutputStream(new FileOutputStream(filePath))) {
			            objOut.writeObject(admin);
			        } catch (IOException e2) {
			            e2.printStackTrace();
			        }
				}
			});
		}
		backButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new LoginGUI(admin);
			}
		});
		backButton2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
				new LoginGUI(admin);
			}
		});
		frame.setVisible(true);
	}
	private void searchExcelScores(int a, int b, int N) {
		//a b ve N değerleri uyan skorları skorborda yazdırır a b N 0 ise tüm skorları yazdırır
	    String filePath = "resources/gunce.xlsx";
	    DefaultTableModel model = (DefaultTableModel) table.getModel();
	    model.setRowCount(0);

	    try {
	        FileInputStream file = new FileInputStream(new File(filePath));
	        Workbook workbook = new XSSFWorkbook(file);
	        Sheet sheet = workbook.getSheetAt(0);

	        List<Object[]> matchingRows = new ArrayList<>();

	        for (int rowNum = 1; rowNum <= sheet.getLastRowNum(); rowNum++) {
	            Row row = sheet.getRow(rowNum);
	            int rowA = (int) row.getCell(3).getNumericCellValue();
	            int rowB = (int) row.getCell(4).getNumericCellValue();
	            int rowN = (int) row.getCell(5).getNumericCellValue();


	            if (rowA == a && rowB == b && rowN == N) {
	                String name = row.getCell(0).getStringCellValue();
	                String date = row.getCell(1).getStringCellValue();
	                int score = (int) row.getCell(2).getNumericCellValue();

	                matchingRows.add(new Object[]{name, score, date});
	            }
	            else if(a == 0 && b == 0 && N == 0) {
	            	String name = row.getCell(0).getStringCellValue();
	                String date = row.getCell(1).getStringCellValue();
	                int score = (int) row.getCell(2).getNumericCellValue();

	                matchingRows.add(new Object[]{name, score, date});
	            }
	        }

	        
	        matchingRows.sort((row1, row2) -> Integer.compare((int) row2[1], (int) row1[1]));

	        for (int i = 0; i < matchingRows.size(); i++) {
	            model.addRow(matchingRows.get(i));
	        }

	        file.close();
	        workbook.close();
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}
}
