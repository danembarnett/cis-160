/*	Author: Dane Barnett
 * 	Date  : 6/11/2017
 *  Purpose: PoliceOfficer class is used to determine
 *  		 if a ParkedCar should get a ticket.
 */

/**
 *  PoliceOfficer class is used to check the ParkedCar and determines if it should get a ticket
 */
public class PoliceOfficer 
{
	private String pName;
	private String bNumber;
	private ParkedCar pCar;
	private ParkingMeter pMeter;
	
	/**
	 *  Constructor is used to insert the values of the PoliceOfficer.
	 */
	public PoliceOfficer(String name, String badge, ParkedCar pc, ParkingMeter pm) 
	{
		pName = name;
		bNumber = badge;
		pCar = pc;
		pMeter = pm;
		checkParking();
	}
	
	/**
	 *  void method is used to check the ParkingMeter and ParkedCar
	 *  and determines if the ParkedCar should get a ticket.
	 */
	public void checkParking()
	{
		
		if (pCar.getParkMinutes() > pMeter.getParkminutes()) {
			ParkingTicket pTicket = new ParkingTicket(pCar, this, pMeter);
			System.out.println(pTicket.getParkingTicket());
		}
		else {
			System.out.println("No Parking Ticket required\n\n");
		}
	}
	
	/**
	 * String method used to get the name of the PoliceOfficer.
	 */
	public String getName()
	{
		return pName;
	}
	
	/**
	 * String method used to get the badge number of the PoliceOfficer.
	 */
	public String getBadgeNumber()
	{
		return bNumber;
	}
	
	
	
	
	
}
