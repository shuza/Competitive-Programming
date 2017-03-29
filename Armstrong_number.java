import java.util.Scanner;

public class Armstrong_number {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number: ");
		int num = input.nextInt();
		int test = num;
		int sum = 0;
		while(test != 0){
			sum += Math.pow((test % 10), 3);
			test /= 10;
		}
		if(sum == num)
			System.out.println(num + " is Armstrong number...");
		else
			System.out.println(num + " is not Armstrong number...");
	}
}