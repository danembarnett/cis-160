/*	Author: Dane Barnett
 * 	Date  : 6/11/2017
 *  Purpose: ParkingMeter responsible for knowing the parking minutes that was purchased
 */

public class ParkingMeter {
	
	
	private int parkMinutes;
	
	/**
	 *  Constructor with one parameter representing the number of parking minutes.
	 */
	public ParkingMeter(int pM)
	{
		this.parkMinutes = pM;
	}
	/**
	 *  int method used to return parking minutes.
	 */
	public int getParkminutes()
	{
		return this.parkMinutes;
	}
	
	
}
