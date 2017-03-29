import java.util.Scanner;

public class Marge_Sort {
	static int[] A;
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int N = input.nextInt();
		System.out.print("Enter the values: ");
		A = new int[N];
		for(int i = 0; i < N; i++)
			A[i] = input.nextInt();
		marge_fun(0, N - 1);
		System.out.print("After sort: ");
		for(int i = 0; i < N; i++)
			System.out.print(A[i] + " ");
	}
	private static void marge_fun(int low, int high) {
		int mid = (low + high) / 2;
		if(low < high){
			marge_fun(low, mid);
			marge_fun(mid + 1, high);
			marge_marge(low, mid, high);
		}
	}
	private static void marge_marge(int low, int mid, int high) {
		int i, j, h;
		i = low;
		j = 0;
		h = mid + 1;
		int[] B = new int[high - low + 1];
		while(i <= mid && h <= high){
			if(A[i] < A[h]){
				B[j] = A[i];
				i++;
				j++;
			}
			else{
				B[j] = A[h];
				j++;
				h++;
			}
		}
		if(i <= mid)
			while(i <= mid){
				B[j] = A[i];
				j++;
				i++;
			}
		else
			while(h <= high){
				B[j] = A[h];
				j++;
				h++;
			}
		for(i = 0; i < j; i++)
			A[low + i] = B[i];
	}
}