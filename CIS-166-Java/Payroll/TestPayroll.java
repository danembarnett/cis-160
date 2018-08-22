/*
	Author: 	Dane Barnett
	Date:		5/27/2017
	Purpose:	TestPayroll.java is a class that consist of a main method
				which is used to create an object from the Payroll class
				and return the calculation and the values of the object
				that is created.
 */

import javax.swing.JOptionPane;

public class TestPayroll {
	
	// main method is used to start the program.
	public static void main(String[] args) {
		
		// variable declarations
		String name;
		int id;
		
		// variable name and id is the value of the dialog box input.
		name = JOptionPane.showInputDialog("Enter Your name: ");
		id = Integer.parseInt(JOptionPane.showInputDialog("Enter " + name + "'s ID: "));
		
		// object creation from Payroll class.
		Payroll pay = new Payroll(name, id);
		
		// setRate and setHours is the value of the dialog box input
		pay.setRate(Double.parseDouble(JOptionPane.showInputDialog("Enter " + name + "'s hourly rate: ")));
		pay.setHours(Double.parseDouble(JOptionPane.showInputDialog("Enter the number of hours " + name + " worked")));
		
		// printPayroll() return a string to the showMessageDialog() method.
		JOptionPane.showMessageDialog(null, pay.printPayroll());

	}

}
