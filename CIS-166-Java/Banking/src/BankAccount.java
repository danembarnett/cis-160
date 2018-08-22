/*Author: Dane Barnett
 * 	Date  : 6/22/2017
 *  Purpose: BankAccount superclass of SavingsAccount is used to withdraw and deposit random amount of money.
 *  
 */

/**Bank Account is a abstract class consisting of fields with that of a real Bank Account*/
public abstract class BankAccount {
	
	private double balance;
	private int depositCount = 0;
	private int withdrawalCount = 0;
	private double interestRate;
	private double monthlyCharges;
	
	/**Constructor has two parameters which takes the balance and interest each time a object is created*/
	public BankAccount(double b, double i)
	{
		balance = b;
		interestRate = i;
	}
	
	/**Constructor with no parameter initializes balance and interest to zero*/
	public BankAccount()
	{
		this(0.0,0.0);
	}
	/**getBalance returns the balance field*/
	public double getBalance()
	{
		return balance;
	}
	/** getWithdrawal returns the withdrawalCount field*/
	public int getWithdrawal()
	{
		return withdrawalCount;
	}
	
	/**deposit takes money parameter and adds it to the balance. It also increments the depositCount field*/
	public void deposit(double money)
	{
		balance += money;
		depositCount++;
	}
	/**withdrawal takes money parameter and subtracts it from the balance field. It also increments the withdrawalCount field*/
	public void withdrawal(double money)
	{
		balance -= money;
		withdrawalCount++;
	}
	
	/**calcInterest calculate the interest and adds it to the balance*/
	public void calcInterest()
	{
		double monthlyInterest;
		
		monthlyInterest = (interestRate / 100) / 12;
		monthlyInterest = balance * monthlyInterest;
		balance += monthlyInterest;	
	}
	
	/**monthlyProcess subtracts the monthly charges from the balance and reset 3 of 5 field values to zero*/
	public void monthlyProcess()
	{
		monthlyCharges = (withdrawalCount - 5)  * 2;
		balance -= monthlyCharges;
		calcInterest();
		this.withdrawalCount = 0;
		this.depositCount = 0;
		this.monthlyCharges = 0;
	}
	
	/**toString returns a String containing the values of the field*/ 
	public String toString()
	{
		return "Account Balance : $" + balance +
				"\nNumber of Deposit : " + depositCount +
				"\nNumber of Withdrawal : " + withdrawalCount +
				"\nAnnual Interest Rate : " + interestRate +
				"\nMonthly Service Charge : $" + monthlyCharges;
				
	}
}
