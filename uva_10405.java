import java.util.Scanner;

public class uva_10405 {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String line1 = input.nextLine();
			String line2 = input.nextLine();
			int m, n, i, j = 0;
			m = line1.length();
			n = line2.length();
			int[][] table = new int[m + 1][n + 1];
			for(i = 0; i <= m; i++)
				table[i][0] = 0;
			for(i = 0; i <= n; i++)
				table[0][i] = 0;
			for(i = 1; i <= m; i++){
				for(j = 1; j <= n; j++){
					if(line1.charAt(i - 1) == line2.charAt(j - 1)){
						table[i][j] = table[i - 1][j - 1] + 1;
					}else if(table[i - 1][j] > table[i][j - 1]){
						table[i][j] = table[i - 1][j];
					}else{
						table[i][j] = table[i][j - 1];
					}
				}
			}
			System.out.println(table[i-1][j-1]);
		}
	}
}