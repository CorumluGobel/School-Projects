package OOP_Project;

import java.io.Serializable;
import java.util.List;

public class Admin implements Serializable{
	private String userName;
	private String password;
	private List<ChildAccount> conectedAccounts;
	private static final long serialVersionUID = 1336783321907333497L;
	
	public Admin(String userName, String password) {
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

	public List<ChildAccount> getConectedAccounts() {
		return conectedAccounts;
	}

	public void setConectedAccounts(List<ChildAccount> conectedAccounts) {
		this.conectedAccounts = conectedAccounts;
	}
}
