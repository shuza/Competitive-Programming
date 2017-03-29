import java.util.Scanner;

public class Ternary_search {
	
	static int[] a;
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int n = input.nextInt();
		int i, j, test;
		a = new int[n];
		System.out.print("Enter data: ");
		for(i = 0; i < n; i++)
			a[i] = input.nextInt();
		for(i = 0; i < n; i++)
			for(j = 1; j < n; j++)
				if(a[j-1] > a[j]){
					test = a[j-1];
					a[j-1] = a[j];
					a[j] = test;
				}
		System.out.print("Enter the search data: ");
		int data = input.nextInt();
		test = ternarySearch(0, n-1, data);
		if(test != -1)
			System.out.println("Data found....");
		else
			System.out.println("Data not found....");
	}

	private static int ternarySearch(int start, int end, int data) {
		int left = start + (end - start) / 3;
		int right = start + 2 * (end - start) / 3;
		if(start > end)
			return -1;
		if(data == a[start])
			return start;
		if(data == a[end])
			return end;
		if(data == a[left])
			return left;
		if(data == a[right])
			return right;
		if(data < a[left])
			return ternarySearch(start + 1, left - 1, data);
		else if(data < a[right])
			return ternarySearch(left + 1, right - 1, data);
		return ternarySearch(right + 1, end - 1, data);
	}
}