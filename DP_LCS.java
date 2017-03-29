import java.util.Scanner;

public class DP_LCS {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the first text: ");
		String X, Y;
		X = input.next();
		System.out.print("Enter the second text: ");
		Y = input.next();
		int n, m, i, j = 0;
		m = X.length();
		n = Y.length();
		int[][] table = new int[m+1][n+1];
		char[][] print = new char[m+1][n+1];
		for(i = 0; i <= m; i++)
			table[i][0] = 0;
		for(i = 0; i <= n; i++)
			table[0][i] = 0;
		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				if(X.charAt(i - 1) == Y.charAt(j - 1)){
					table[i][j] = table[i - 1][j - 1] + 1;
					print[i][j] = '+';
				}else if(table[i - 1][j] > table[i][j - 1]){
					table[i][j] = table[i - 1][j];
					print[i][j] = '^';
				}else{
					table[i][j] = table[i][j - 1];
					print[i][j] = '-';
				}
			}
		}
		PRINT(print, X, i - 1, j - 1);
		System.out.printf("\n\tEnd....");
	}

	private static void PRINT(char[][] print, String x, int i, int j) {
		if(i == 0 || j == 0)
			return;
		if(print[i][j] == '+'){
			PRINT(print, x, i - 1, j - 1);
			System.out.print(x.charAt(i - 1));
		}else if(print[i][j] == '^'){
			PRINT(print, x, i-1, j);
			System.out.print("*");
		}
		else{
			PRINT(print, x, i, j-1);
			System.out.print("*");
		}
	}
}