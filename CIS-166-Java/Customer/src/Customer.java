
public class Customer extends Person
{
	private int customerNum;
	private boolean mailingList;
	
	
	public Customer(String a, String b, String c, int d, boolean m)
	{
		super(a,b,c);
		customerNum = d;
		mailingList = m;
		
	}
	
	public boolean MailList()
	{
		return mailingList;
	}
	
	public int customerNum()
	{
		return customerNum;
	}
	
	public String getDecision()
	{
		if (MailList() == true)
			return "You are on the mailing list!";
		else
			return "You are not on the mailing list :( ";
	}
	
	public String toString()
	{
		return  super.toString() + "\nCustomer Number: " + customerNum +
				"\n" + getDecision();
		
	}
}
