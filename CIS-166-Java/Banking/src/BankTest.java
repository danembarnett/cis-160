
import java.util.Random;

public class BankTest {
	// main program
	public static void main(String[] args) {
		
		int INT_VALUE = 5;
		double[] arr;
		SavingsAccount[] accountArray = new SavingsAccount[INT_VALUE];
		
		for (int i = 0; INT_VALUE > i; i++)
		{
			accountArray[i] = new SavingsAccount(randomBalance(), randomInterest());
			arr = randomArray();
			System.out.println("\n  Savings Account # " + (i + 1) + "\n");
			for (int x = 0; arr.length > x; x++)
			{
				int answer = depositWithdraw();
		
				if (answer == 1)
					accountArray[i].deposit(arr[x]);
				else
					accountArray[i].withDraw(arr[x]);
			}
			
			accountArray[i].monthlyProcess();
			System.out.println(accountArray[i]);
		}
		

	}
	
	//randomBance generates a random amount of money to either deposit or withdraw
	public static double randomBalance()
	{
		Random balance = new Random();
		int low = 50;
		int high = 200;
		double randomBalance = balance.nextInt(high-low) + low;
		
		return randomBalance;
	}
	
	// randomInterst generates a random interest value for the savings account object
	public static double randomInterest()
	{
		Random interest = new Random();
		int low = 5;
		int high = 50;
		double randomInterest = interest.nextInt(high-low) + low;
		
		return randomInterest;
	}
	
	// randomArray generates a random array
	public static double[] randomArray()
	{
		Random value1 = new Random();
		int low1 = 30;
		int high1 = 365;
		int randomValue1 = value1.nextInt(high1-low1) + low1;
		
		double array[] = new double[randomValue1];
		
		for (int i = 0; array.length > i; i++)
		{
			Random value2 = new Random();
			int low2 = 1;
			int high2 = 1000;
			int randomValue2 = value2.nextInt(high2-low2) + low2;
			
			array[i] = randomValue2;
		}
		
		return array;
	}
	
	//depositWithdraw returns an int which represent deposit or withdraw for the main function
	public static int depositWithdraw()
	{
		Random value3 = new Random();
		
		int low3 = 1;
		int high3 = 3;
		int randomValue3 = value3.nextInt(high3-low3) + low3;
		
		
		return randomValue3;
	}

}
