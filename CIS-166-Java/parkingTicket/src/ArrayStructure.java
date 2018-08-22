
public class ArrayStructure {
	
	private int[] theArray = new int[50];
	
	int arraySize = 10;
	
	public void generateRandomArray()
	{
		for(int i = 0; i < arraySize; i++)
		{
			theArray[i] = (int)(Math.random()*10)+10;
					
		}
	}
	
	public void printArray()
	{
		System.out.println("----------");
		for(int i = 0; i < arraySize; i++)
		{
			
		}
	}
	public static void main(String[] args) 
	{
		
		
		

	}

}
