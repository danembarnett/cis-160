import java.util.Scanner;
public class CustomerTest 
{

	public static void main(String[] args)
	{
		String a,b,c;
		int d;
		char selection;
		boolean e;
		
		Scanner input = new Scanner(System.in);
		
		
		System.out.println("Enter in your Name: ");
		a = input.nextLine();
		System.out.println("Enter your Address: ");
		b = input.nextLine();
		System.out.println("Enter  your telephone Number: ");
		c = input.nextLine();
		System.out.println("Enter in your  Customer ID: ");
		d = input.nextInt();
		
		System.out.println("Would you like to be apart of the Mailing List? [Y/N] : ");
		selection = input.next().charAt(0);
		
		if ( selection == 'Y')
			e = true;
		else 
			e = false;
		
		
	
		Customer c1 = new Customer(a,b,c,d,e);
		
		System.out.println(c1);
		
		input.close();
	}

}
