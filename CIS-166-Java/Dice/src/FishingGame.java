/* 
 *  Author: Dane Barnett
 *  Date: 06/06/2017
 *  Purpose: FishingGame is main method that creates a new object
 *  		 from the Die class, this program is a fishing game.
 */

import java.io.IOException;
import java.util.Scanner;


public class FishingGame {

	public static void main(String[] args) throws IOException 
	{
		// variable declaration
		boolean start = true;
		String choice;
		Scanner keyboard = new Scanner(System.in);

		// run the loop if start is true
		while(start) 
		{
			// FishGame is a new Die class object which has a argument value of 6
			Die fishGame = new Die(6);
			System.out.println("Enter You Name : "); // enter name for scores.txt
			fishGame.setName(keyboard.nextLine());
			
			// Start of the fishing game
			System.out.println("Welcome to Dane's Fishing Game! Do you want to play? Enter yes or no");
			choice = keyboard.nextLine();
				
				// a loop with in a loop that continues if the start is true
				do {
					// if user input is not yes and not false, this creates an infinity loop
					while (!choice.matches("yes") && !choice.matches("no")) 
					{
						System.out.println("\nInvalid input, Please enter yes or no");
						choice = keyboard.nextLine();
					}
					//rollDice is called when user enter "yes"
					if (choice.matches("yes")) {
						fishGame.rollDice();
						
						
					}
					// game ends if user enter "no"
					else if(choice.matches("no")) {
						System.out.println("\nThank You for Playing");
						System.out.println(fishGame.getScoreMessage());
						start = false;
						break;
					}
					
					// if user enter "yes" the dice is rolled again, if user enter "no", the game ends.
					System.out.println("\nDo you want to fish again?");
					choice = keyboard.nextLine();
					while (!choice.matches("yes") && !choice.matches("no")) 
					{
						System.out.println("\nInvalid input, Please enter yes or no");
						choice = keyboard.nextLine();
					}
					if (choice.matches("yes"))
						start = true;
					else {
						System.out.println("\nThank You for Playing!");
						System.out.println(fishGame.getScoreMessage());
						start = false;
					}
					
				}
				// game breaks out of the do while loop when start = false
				while(start);
				
				// user enter yes to save the names and the scores to scores.txt
				System.out.println("\nDo you want to save the score? ");
				choice = keyboard.nextLine();
				if (choice.equals("yes")) {
					fishGame.saveScore();
					System.out.println("\nGame saved!");
					keyboard.close();
				}
				else {
					System.out.println("Okay! Game not saved!");
					keyboard.close();
				}
				
			}
		}
}