package demo.selenium;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

public class Chimani {

	public static void main(String[] args) throws InterruptedException {
		
		System.setProperty("webdriver.chrome.driver","C:\\Users\\iet35\\Desktop\\Software Testing\\selenium\\chromedriver_win32\\chromedriver.exe");
		
		WebDriver driver=new ChromeDriver();
		
		driver.get("https://github.com/login?return_to=%2Fgithub");
		
		Thread.sleep(2000);
		
		driver.findElement(By.name("login")).sendKeys("SachinKhakare");
		
		Thread.sleep(2000);
		
		driver.findElement(By.id("password")).sendKeys("samarth@31");
		
		Thread.sleep(2000);
		
		driver.findElement(By.name("commit")).click();
		
		Thread.sleep(2000);
		
		
		
		
		
		
		

	}

}
