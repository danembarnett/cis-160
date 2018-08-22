
public class Person 
{
	private String name;
	private String address;
	private String telephone;
	
	public Person (String n, String a, String t)
	{
		name = n;
		address = a;
		telephone = t;
	}
	
	public Person ()
	{
		this("", "", "");
	}
	
	public String getName()
	{
		return name;
	}
	
	public String getAddress()
	{
		return address;
	}
	
	public String getTelephone()
	{
		return telephone;
	}
	
	// getName() 
	public String toString()
	{
		return "Name: " + getName() + 
				"\nAddress: "+ address + 
				"\nTelephone Number: " + telephone;
	}
}
