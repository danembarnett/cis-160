/*	Author: Dane Barnett
 * 	Date  : 6/11/2017
 *  Purpose: ParkedCar class creates a Car object
 */

/**
 *  ParkedCar is a class that provides the car data
 */
public class ParkedCar {
	
	private String make;
	private String model;
	private int year;
	private String color;
	private String licenseNum;
	private int parkMinutes;

	
	
	/**
	 * Constructor class is used to initialize the Car values
	 */
	public ParkedCar(String ma, String mo, int y, String c, String lNum, int pm) 
	{
		this.make = ma;
		this.model = mo;
		this.year = y;
		this.color = c;
		this.licenseNum = lNum;
		this.parkMinutes = pm;
	}
	
	/**
	 * String method that returns the make of the car.
	 */
	public String getMake() 
	{
		return this.make;
	}
	/**
	 * String method that returns the model of the car.
	 */
	public String getModel()
	{
		return this.model;
	}
	/**
	 * int method that returns the year the car was made.
	 */
	public int getYear()
	{
		return this.year;
	}
	/**
	 * String method that returns the color of the car.
	 */
	public String getColor()
	{
		return this.color;
	}
	/**
	 * String method that returns the license plate number of the car.
	 */
	public String getLicenseNum()
	{
		return this.licenseNum;
	}
	/**
	 * String method that returns the amount of time the car has been parked.
	 */
	public int getParkMinutes()
	{
		return this.parkMinutes;
	}
}
