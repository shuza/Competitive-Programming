import java.util.Scanner;

public class uva_10130 {
	
	static int[] b;
	static int[] w;
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		while(T > 0){
			int n = input.nextInt();
			int i, j, ob;
			b = new int[n+1];
			w = new int[n+1];
			for(i = 1; i <= n; i++){
				b[i] = input.nextInt();
				w[i] = input.nextInt();
			}
			ob = input.nextInt();
			int max = 0;
			for(i = 0; i < ob; i++){
				j = input.nextInt();
				max += maxProfit(n, j);
			}
			System.out.println(max);
			T--;
		}
	}
	static int maxProfit(int n,int W){
		int i, j;
		int[][] table = new int[n+1][W+1];
		for(i = 0; i <=n; i++)
			table[i][0] = 0;
		for(j = 0; j <= W; j++)
			table[0][j] = 0;
		for(i = 1; i <= n; i++)
			for(j = 0; j <= W; j++)
				if(w[i] <= j){
					if((b[i] + table[i-1][j - w[i]]) > table[i-1][j])
						table[i][j] = b[i] + table[i-1][j - w[i]];
					else
						table[i][j] = table[i-1][j];
				}else
					table[i][j] = table[i-1][j];
		return table[n][W];
	}
}