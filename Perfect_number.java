import java.util.Scanner;

public class Perfect_number {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number: ");
		int num = input.nextInt();
		int sum = 1;
		int i;
		for(i = 2; i <= num / 2; i++)
			if(num % i == 0)
				sum += i;
		if(sum == num)
			System.out.println(num + " is perfect number...");
		else
			System.out.println(num + " is not perfect number...");
	}
}