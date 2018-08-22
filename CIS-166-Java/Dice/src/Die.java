/* 
 *  Author: Dane Barnett
 *  Date: 06/06/2017
 *  Purpose: A Die class which consist a program that rolls
 *  		 a virtual Dice and return the values and score
 *  		 of the game.
 */

import java.util.Random;
import java.io.*;
import java.util.Scanner;

/** Die class
 * 
 *A Dice Game that rolls a virtual Dice and return the score
 */
public class Die 
{

	private int side;
	private int value;
	private int score;
	private String name;
	private String[] myRead = new String[14];
	
	/**
	 *  private addScore method accepts integer and executes switch statement 
	 */
	private void addScore(int v) 
	{
		switch (v) 
		{
		case 1:
			this.score += Integer.parseInt(myRead[1]);
			System.out.println("\nYou caught " + myRead[0]);
			break;
		case 2:
			this.score += Integer.parseInt(myRead[3]);
			System.out.println("\nYou caught " + myRead[2]);
			break;
		case 3:
			this.score += Integer.parseInt(myRead[5]);
			System.out.println("\nYou caught " + myRead[4]);
			break;
		case 4:
			this.score += Integer.parseInt(myRead[7]);
			System.out.println("\nYou caught " + myRead[6]);
			break;
		case 5:
			this.score += Integer.parseInt(myRead[9]);
			System.out.println("\nYou caught " + myRead[8]);
			break;
		case 6:
			this.score += Integer.parseInt(myRead[11]);
			System.out.println("\nYou caught " + myRead[10]);
			break;
		default:
			this.score += 0;
			System.out.println("\nYou didn't catch anything!");
		}
	}
	
	/**
	 * private method setItem reads param.txt and set the value inside of the myRead array.
	 */
	private void setItem() throws FileNotFoundException 
	{
		int count = 0;
		
		File file = new File("param.txt");
		Scanner inputFile = new Scanner(file);

		while (inputFile.hasNext()) 
		{
			myRead[count] = inputFile.nextLine();
			count++;
		}
		inputFile.close();
	}
	
	/**
	 * 	Constructor method accepts the number of side for the Dice.
	 */
	public Die(int s) throws FileNotFoundException 
	{
		side = s;
		setItem();
	}
	
	/**
	 *setName method is used to accept String and apply the value to name.
	 */
	public void setName(String n)
	{
		name = n;
	}
	
	/**
	 * getName returns the value of private String name.
	 */
	public String getName() 
	{
		return this.name;
	}
	
	/**
	 * rollDice method creates a new random object, sets the random number
	 * to private value and execute the add score method
	 */
	public void rollDice() 
	{
		Random rand = new Random();
		this.value = rand.nextInt(this.side + 1);
		addScore(this.value);
	}
	
	/**
	 *  getScore returns the value of private score
	 */
	public int getScore() 
	{
		return this.score;
	}
	
	/**
	 * getScoreMessage returns a string depending on the value of the score.
	 */
	public String getScoreMessage() {
		
		if (this.score < Integer.parseInt(myRead[12]))
			return "\nCongratulations " + getName() + "! You have a low score of " + this.score;
		else if(this.score >= Integer.parseInt(myRead[12]) && this.score < Integer.parseInt(myRead[13]))
			return "\nCongratulations " + getName() + "! You have a medium score of " + this.score;
		else if(this.score >= Integer.parseInt(myRead[13]))
			return "\nCongratulations " + getName() + "! You have a high score of " + this.score;
		else {
			return null;
		}
	}
	
	/**
	 * saveScore method save the name and score to scores.txt file.
	 */
	public void saveScore() throws IOException {
		
			FileWriter fw = new FileWriter("scores.txt", true);
			PrintWriter file = new PrintWriter(fw);
	
			file.println("Name : " + getName() + "\t\tScore : " + this.getScore());
			
			file.close();
	}
}
