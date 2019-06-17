package training.demo.test;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.annotations.AfterSuite;
import org.testng.annotations.AfterTest;
import org.testng.annotations.BeforeSuite;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;


public class SeleniumTest 
{
	WebDriver  driver=null;
	
	//Opening Window
  @BeforeSuite
  public void openTest()
  {
	  System.setProperty("webdriver.chrome.driver", "C:\\iet81\\selenium_WebDriver\\selenium_lib\\chromedriver.exe");
	   driver= new ChromeDriver();
	 
	  driver.manage().window().maximize();
	  driver.get("https://opensource-demo.orangehrmlive.com/");
	  
  }
  
  //Login
  @BeforeTest
  public void login() throws InterruptedException
  {
	  driver.findElement(By.name("txtUsername")).sendKeys("Admin");
	  driver.findElement(By.name("txtPassword")).sendKeys("admin123");
	  driver.findElement(By.xpath("//*[@id=\"btnLogin\"]")).click();
	  Thread.sleep(200);
  }
  
  
  @Test
  public void Test1() throws InterruptedException
  {
	  //Add employee
	  
	  Thread.sleep(1000);
	  driver.findElement(By.linkText("Admin")).click();
		
	 Thread.sleep(1000);
	 driver.findElement(By.name("btnAdd")).click();
		
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[userType]")).sendKeys("ESS");
			
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[employeeName][empName]")).sendKeys("abi Parthi");
			
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[userName]")).sendKeys("smita");
			
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[status]")).sendKeys("Enabled");
			
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[password]")).sendKeys("12345678");
			
	Thread.sleep(1000);
	driver.findElement(By.name("systemUser[confirmPassword]")).sendKeys("12345678");
			
	Thread.sleep(1000);
	driver.findElement(By.name("btnSave")).click();
  }
  
  /*
  //Logout
  @AfterTest
  public void logout() throws InterruptedException
  {
	  Thread.sleep(200);
	  driver.findElement(By.xpath("//*[@id=\"welcome\"]")).click();
	  Thread.sleep(200);
	  driver.findElement(By.xpath("//*[@id=\"welcome-menu\"]/ul/li[2]/a")).click();
  }
  
  /*
  //Closing the window
  @AfterSuite
  public void closeTest()
  {
	  driver.close();
  }
  */
}
