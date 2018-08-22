/*
	Author: 	Dane Barnett
	Date:		5/27/2017
	Purpose:	Payroll is a class which consist of methods
				that will be access by TestPayroll.java. Payroll
				consist of methods such as setPay and setRate and also
				have a default constructor which takes 2 arguments.
 */

import java.text.DecimalFormat;

/* Payroll class consist of methods such as setName and setID */
public class Payroll {
	
	// member attributes is not accessible from programs outside the class.
	private String employeeName;
	private int employeeID;
	private double payRate;
	private double workHours;
	
	/* constructor with name and id parameters. */
	public Payroll(String name, int id) 
	{
		employeeName = name;
		employeeID = id;
	}
	/* setName method used to apply String value to the employeeName field. */
	public void setName(String name) 
	{
		employeeName = name;
	}
	
	/* setID method is used to apply int value to the employeeID field. */
	public void setID(int id) 
	{
		employeeID = id;
	}
	
	/* setRate method is used to apply double value to the payRate field. */
	public void setRate(double pay) 
	{
		payRate = pay;
	}
	
	/* setHours method is used to apply double value to the workHours field. */
	public void setHours(double hours) 
	{
		workHours = hours;
	}
	
	/* getName() method is used to return a String value of the employeeName field. */
	public String getName() 
	{
		return employeeName;
	}
	
	/* getID() method is used to return an int value of the employeeID field. */
	public int getID() 
	{
		return employeeID;
	}
	
	/* getRate() method is used to return a double value of the payRate field. */
	public double getRate() 
	{
		return payRate;
	}
	
	/* getHours() method is used to return a double value of the workHours field. */
	public double getHours() 
	{
		return workHours;
	}
	
	/* grossPay() method return the value of payRate multiply by the value of workHours. */
	public double grossPay() 
	{
		return payRate * workHours;
	}
	
	/* printPayroll() method is used to return a String. */
	public String printPayroll() 
	{
		// Decimal format object is created to format double type to 2 decimal places.
		DecimalFormat formatter = new DecimalFormat("#0.00");   
		
		return "\t\t" + employeeName + "'s Payroll\n\nName             : " + getName() +
				"\nEmployeeID   : " + getID() + "\nPay Rate         : $" + formatter.format(getRate()) +
				"\nWork Hours    : " + formatter.format(getHours()) + 
				"\nGross Pay       : $" + formatter.format(grossPay());	
	}
	

}
