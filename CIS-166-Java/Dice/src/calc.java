
public class calc {

	public static void main(String[] args) {
		int highNum = 30;
		int lowNum = 1;
		double answer = 0;
		for (int x = highNum; x > 0; x--)
		{
			answer += lowNum / highNum;
			highNum--;
			lowNum++;
		}
		
		System.out.println(answer);;

	}

}
