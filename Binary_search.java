import java.util.Scanner;

public class Binary_search {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int n = input.nextInt();
		System.out.print("Enter the value: ");
		int i, j, mid;
		int[] a = new int[n];
		for(i = 0; i<n; i++)
			a[i] = input.nextInt();
		for(i = 0; i<n; i++)
			for(j = 1; j<n; j++)
				if(a[j-1]>a[j]){
					mid = a[j-1];
					a[j-1] = a[j];
					a[j] = mid;
				}
		System.out.print("Enter the search data: ");
		int data = input.nextInt();
		i = 0;
		j = n-1;
		mid = j/2;
		while(a[mid] != data && mid < j){
			if(data > a[mid]){
				i = mid + 1;
				mid = (i + j)/2;
			}else{
				j = mid - 1;
				mid = (i + j)/2;
			}
		}
		if(a[mid] == data)
			System.out.println("Data found");
		else
			System.out.println("Data not found");
	}
}