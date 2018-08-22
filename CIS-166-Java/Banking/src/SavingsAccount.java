/*Author: Dane Barnett
 * 	Date  : 6/22/2017
 *  Purpose: BankAccount superclass of SavingsAccount is used to withdraw and deposit random amount of money.
 *  
 */

/**SavingsAccount is a subclass of BankAccount*/
public class SavingsAccount extends BankAccount {
	
	boolean status;
	
	/**Constructor has two parameters which calls the superclass*/
	public SavingsAccount(double b, double i)
	{
		super(b, i);
	}
	
	/**Constructor with no parameter initializes balance and interest to zero*/
	public SavingsAccount()
	{
		this(0.0,0.0);
	}
		
	/**money is deposited to the superclass field balance under a certain condition*/
	public void deposit(double a)
	{
		super.deposit(a);
		if (super.getBalance() > 20)
			status = true;
		else
			status = false;
	}
	/**money can be withdraw from the superclass field balance under a certain condition*/
	public void withDraw(double a)
	{
		if (super.getBalance() > 20)
			super.withdrawal(a);
		else
			status = false;
	}
	
	/**monthlyProcess calls the superclass method*/
	public void monthlyProcess()
	{
		if(super.getWithdrawal() > 5)
			super.monthlyProcess();
		else
			status = false;
	}
	
	/**getStatus returns the a string that evaluates if the account is active for inactive*/
	public String getStatus()
	{
		if (super.getBalance() < 20)
			return "Inactive";
		else
			return "Active";
	}
	
	/**toString calls the superclass method and the getStatus method*/
	public String toString()
	{
		return super.toString() + "\nAccount Status : " + getStatus();		
				
	}
}
