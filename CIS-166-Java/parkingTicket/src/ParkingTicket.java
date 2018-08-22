/*	Author: Dane Barnett
 * 	Date  : 6/11/2017
 *  Purpose: ParkingTicket class is used to print the ticket.
 */

import java.util.Calendar;

/**
 *  ParkingTicket class generates a ticket.
 */
public class ParkingTicket {
	
	private ParkedCar pCar;
	private PoliceOfficer pOfficer;
	private ParkingMeter pMeter;
	
	
	/**
	 *  Constructor has three parameter for helping with the process of printing the tickets
	 */
	public ParkingTicket(ParkedCar p, PoliceOfficer po, ParkingMeter pm)
	{
		pCar = p;
		pOfficer = po;
		pMeter = pm;
	}
	
	/**
	 *  int method used to calculate if the ParkedCar and the ParkingMeter
	 *  to determine if the ParkedCar is due for a ticket.
	 */
	public int overDue()
	{
		return (pCar.getParkMinutes() - pMeter.getParkminutes()) / 60;
	}
	
	/**
	 *  double method used to calculate the penalty cost.
	 */
	public double calcFine() 
	{
		return ((overDue() - 1) * 20) + 50;
	}
	
	/**
	 *  String method used to return the date and time of the ticket.
	 */
	public String getTime() 
	{
		Calendar calendar = Calendar.getInstance();
		
		return calendar.getTime().toString();
	}
	
	/**
	 * String method used to print the ticket.
	 */
	public String getParkingTicket()
	{
		
		return "\n\t Parking Ticket\n" +
				"\nDate Issued : " + getTime() +
				"\n*****************************" +
				"\nMake : " + pCar.getMake() +
				"\nModel : " + pCar.getModel() +
				"\nYear : " + pCar.getColor() +
				"\nColor : " + pCar.getYear() +
				"\nLicense Plate # : " + pCar.getLicenseNum() +
				"\n*****************************"
				+ "\nOfficer Name : " + pOfficer.getName() +
				"\nBadge Number : " + pOfficer.getBadgeNumber() +
				"\n*****************************" +
				"\nPurchased Park Time : " + pCar.getParkMinutes() +
				"\nOverdue Time : " + overDue() + " hour(s)" +
				"\nPenalty : $" + calcFine();
	}
}
