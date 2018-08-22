import java.util.Scanner;

public class TestCircle {

	public static void main(String[] args) {
		
		Circle smallCircle = new Circle();
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Enter radius : ");
		smallCircle.setRadius(keyboard.nextDouble());
		
		System.out.println("Area : " + smallCircle.getArea());
		System.out.println("Diameter : " + smallCircle.getDiameter());
		System.out.println("Circumference : " + smallCircle.getCircumference());
		
		keyboard.close();

	}

}
