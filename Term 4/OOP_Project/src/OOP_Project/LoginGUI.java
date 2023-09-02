package OOP_Project;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class LoginGUI {
	private JButton login;
	private JTextField userNameField;
	private JPasswordField passwordField;
	public LoginGUI(Admin admin) {
		JFrame frame = new JFrame();
		
		login = new JButton("Login");
		login.setBounds(150, 110, 200, 40);  
		frame.getContentPane().add(login);
		
		userNameField = new JTextField();
		userNameField.setBounds(150, 11, 200, 40);
		frame.getContentPane().add(userNameField);
		passwordField = new JPasswordField();
		passwordField.setBounds(150, 59, 200, 40);
		frame.getContentPane().add(passwordField);
        
		
		frame.setTitle("Login");
		frame.setSize(500,200); 
		frame.getContentPane().setLayout(null);
		
		JLabel userNameLabel = new JLabel("Username:");
		userNameLabel.setBounds(65, 24, 75, 14);
		frame.getContentPane().add(userNameLabel);
		
		JLabel passwordLabel = new JLabel("Password:");
		passwordLabel.setBounds(65, 72, 75, 14);
		frame.getContentPane().add(passwordLabel);
		frame.setVisible(true);
		
		login.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(userNameField.getText().equals(admin.getUserName()) && passwordField.getText().equals(admin.getPassword())) {
					new AdminGUI(admin);
					frame.dispose();
				}
				else {
					for(int i = 0; i < admin.getConectedAccounts().size(); i++) {
						if(userNameField.getText().equals(admin.getConectedAccounts().get(i).getUserName()) && passwordField.getText().equals(admin.getConectedAccounts().get(i).getPassword())) {
							new ChildGUI(admin.getConectedAccounts().get(i), admin);
							frame.dispose();
						}
					}
				}
			}
		});
	}
}
