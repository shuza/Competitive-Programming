import java.util.Scanner;

public class TowerOfHanoi {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number of disk: ");
		int n = input.nextInt();
		int src = 1, other = 2, target = 3;
		hanoi(n, src, other, target);
	}

	private static void hanoi(int n, int src, int other, int target) {
		if(n != 0){
			hanoi(n - 1, src, target, other);
			move(n, src, target);
			hanoi(n - 1, other, src, target);
		}
	}

	private static void move(int n, int src, int target) {
		System.out.println("Move disk " + n + " from " + src + " to " + target);
	}
}