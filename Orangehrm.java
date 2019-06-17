package demo.selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.Select;

public class Orangehrm {

	public static void main(String[] args) throws InterruptedException {
		
		System.setProperty("webdriver.chrome.driver","C:\\Users\\iet35\\Desktop\\Software Testing\\selenium\\chromedriver_win32\\chromedriver.exe");
		
		WebDriver driver=new ChromeDriver();
		
	driver.get("https://opensource-demo.orangehrmlive.com/");	
	
	driver.findElement(By.name("txtUsername")).sendKeys("Admin");
	
	driver.findElement(By.id("txtPassword")).sendKeys("admin123");
	
	driver.findElement(By.xpath("//*[@id=\"btnLogin\"]")).click();
	
	driver.findElement(By.xpath("//*[@id=\"menu_pim_viewPimModule\"]/b")).click();
	
	driver.findElement(By.name("empsearch[employee_name][empName]")).sendKeys("Krushna");
	
	driver.findElement(By.id("empsearch_id")).sendKeys("006");
	
	
	
	WebElement abcd=driver.findElement(By.name("empsearch[employee_status]"));
	
	Select dropdown=new Select (abcd);
	
	dropdown.selectByVisibleText("Full-Time Contract");
	
	driver.findElement(By.xpath("//*[@id=\"welcome\"]")).click();
	Thread.sleep(2000);
	driver.findElement(By.xpath("//*[@id=\"welcome-menu\"]/ul/li[2]/a")).click();
	driver.close();
	}

}
