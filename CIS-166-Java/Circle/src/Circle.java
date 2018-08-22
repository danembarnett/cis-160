public class Circle 
{
	private double radius;
	final private double PI = 3.13159;
	
	public Circle() 
	{
		radius = 0;
		
	}
	
	public void setRadius(double r) 
	{
		radius = r;
	}
	
	public double getRadius() 
	{
		return radius;
	}
	
	public double getArea() 
	{
		return PI * radius * radius;
	}
	
	public double getDiameter() 
	{
		return radius * 2;
	}
	
	public double getCircumference() 
	{
		return PI * radius * 2;
	}
}
