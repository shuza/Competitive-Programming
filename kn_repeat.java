import java.util.Scanner;

public class kn_repeat {
	static int[][] dp = new int[10][30];
	static int[] weight = new int[10];
	static int[] profit = new int[10];
	static int cap, N;
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter element number: ");
		N = input.nextInt();
		System.out.print("Enter weight: ");
		for(int i = 0; i < N; i++)
			weight[i] = input.nextInt();
		System.out.print("Enter profit: ");
		for(int i = 0; i < N; i++)
			profit[i] = input.nextInt();
		System.out.print("Max weight: ");
		cap = input.nextInt();
		for(int i = 0; i < N; i++)
			for(int j = 0; j <=cap; j++)
				dp[i][j] = -1;
		int ans = call(0, 0);
		System.out.print("Ans = " + ans);
	}

	private static int call(int i, int w) {
		if(i == N || w >= cap)
			return 0;
		if(dp[i][w] != -1)
			return dp[i][w];
		int profit1;
		if(w + weight[i] <= cap)
			profit1 = profit[i] + call(i, w + weight[i]);
		else
			profit1 = 0;
		int profit2 = call(i+1, w);
		if(profit1 > profit2)
			dp[i][w] = profit1;
		else
			dp[i][w] = profit2;
		return dp[i][w];
	}
}