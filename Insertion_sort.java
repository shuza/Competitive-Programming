import java.util.Scanner;

public class Insertion_sort {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int n = input.nextInt();
		int array[] = new int[n];
		int i, j;
		System.out.print("Enter the values: ");
		for(i = 0; i < n; i++)
			array[i] = input.nextInt();
		for(i = 1; i < n; i++){
			int key = array[i];
			for(j = i - 1; j >= 0 && key < array[j]; j--)
				array[j + 1] = array[j];
			array[j + 1] = key;
		}
		for (int j1 : array) {
			System.out.print(j1 + " ");
		}
	}
}