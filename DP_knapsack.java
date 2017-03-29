import java.util.Scanner;

public class DP_knapsack {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int n = input.nextInt();
		System.out.print("Enter the profit: ");
		int[] b = new int[n+1];
		int[] w = new int[n+1];
		int i, j;
		for(i = 1; i <= n; i++)
			b[i] = input.nextInt();
		System.out.print("Enter the weight: ");
		for(i = 1; i <= n; i++)
			w[i] = input.nextInt();
		System.out.print("Enter the maximum weight: ");
		int W = input.nextInt();
		int[][] table = new int[n+1][W+1];
		for(i = 0; i <= n; i++)
			table[i][0] = 0;
		for(i = 0; i <= W; i++)
			table[0][i] = 0;
		for(i = 1; i <= n; i++)
			for(j = 0; j <= W; j++)
				if(w[i] <= j){
					if((b[i] + table[i-1][j - w[i]]) > table[i-1][j])
						table[i][j] = b[i] + table[i-1][j - w[i]];
					else
						table[i][j] = table[i-1][j];
				}else
					table[i][j] = table[i-1][j];
		System.out.println("Maximum profit = " + table[n][W]);
		i = n;
		j = W;
		System.out.print("Item weight = ");

		// 		Buttom  up  traverse....
		while(i > 0 && j > 0){
			if(table[i][j] != table[i-1][j]){
				System.out.print(w[i] + "  ");
				j -= w[i];
			}
			i--;
		}
	}
}