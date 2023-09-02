package OOP_Project;

import java.awt.event.ActionListener;
import javax.swing.Timer;
import junit.framework.TestCase;

public class JUnitClass extends TestCase{
	private Admin admin;
	private Timer timer;
	private ActionListener e;
	protected void setUp() {
		admin = new Admin("Emirhan", "123456");
		timer = new Timer(1000, e);
	}
	public void testGetUsername() {
		String username = admin.getUserName();
		assertEquals(username, "Emirhan");
	}
	public void testGetPassword() {
		String password = admin.getPassword();
		assertEquals(password, "123456");
	}
	public void testSetUsername() {
		admin.setUserName("Ali");
		assertEquals("Ali", admin.getUserName());
	}
	public void testSetPassword() {
		admin.setPassword("123");
		assertEquals("123", admin.getPassword());
	}
	public void testStartUpdatingTimer() {
		timer.start();
		assertNotNull(timer);
		assertEquals(1000, timer.getDelay());
		assertTrue(timer.isRunning());
	}
}
