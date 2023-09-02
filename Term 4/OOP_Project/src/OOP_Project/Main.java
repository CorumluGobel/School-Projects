package OOP_Project;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class Main {
	public static void main(String[] args) {
		Admin admin = null;
        String filePath = "resources/users.ser";
        
        try (ObjectInputStream objIn = new ObjectInputStream(new FileInputStream(filePath))) {
            admin = (Admin) objIn.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
		new LoginGUI(admin);
	}
}
