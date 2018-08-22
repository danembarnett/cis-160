
public class TestParking {

	public static void main(String[] args) {
		
		// Test 1
		System.out.println("\tTest 1");
		ParkedCar pCar1 = new ParkedCar("Toyota", "Matrix", 2007, "Grey", "HZL-459", 60);
		ParkingMeter pMeter1 = new ParkingMeter(120);
		PoliceOfficer pOfficer1 = new PoliceOfficer("Dane Barnett", "458HY9", pCar1, pMeter1);
		
		// Test 2
		System.out.println("\tTest 2");
		ParkedCar pCar2 = new ParkedCar("Porsche", "911", 2017, "Metal Black", "F09-R87", 120);
		ParkingMeter pMeter2 = new ParkingMeter(60);
		PoliceOfficer pOfficer2 = new PoliceOfficer("John Rodrigues", "948JH1", pCar2, pMeter2);
		
		// Test 3
		System.out.println("\t\nTest 3");
		ParkedCar pCar3 = new ParkedCar("Mercedees", "X6", 2014, "Pink", "8JI-857", 460);
		ParkingMeter pMeter3 = new ParkingMeter(60);
		PoliceOfficer pOfficer3 = new PoliceOfficer("Dane Barnett", "509GHO", pCar3, pMeter3);
		

	}

}
