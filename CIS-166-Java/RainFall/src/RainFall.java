
public class RainFall {

	
	
	
	public static void main(String[] args) 
	{
		
		double[] RainFall = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
		
		System.out.println(total(RainFall));
		System.out.println(average(RainFall));
		System.out.println(max(RainFall));
		System.out.println(min(RainFall));
		

	}

	public static double total(double[] temp)
	{
		int sum = 0;
		
		for (int i = 0; i < temp.length; i++)
		{
			sum += temp[i];
		}
		return sum;
	}
	
	public static double average(double[] temp)
	{
		return total(temp) / temp.length;
	}
	
	public static int max(double[] temp)
	{
		double maximum = temp[0];
		int index = 0;
		
		for (int i = 1; i < temp.length; i++)
		{
			if (maximum < temp[i])
			{
				maximum = temp[i];
				index = i;
			}
		}
		return index + 1;
	}
	
	public static int min(double[] temp)
	{
		double minimum = temp[0];
		int index = 0;
		
		for (int i = 1; i < temp.length; i++)
		{
			if (minimum > temp[i])
			{
				minimum = temp[i];
				index = i;
			}
		}
		return index + 1;
	}
	
	
}
