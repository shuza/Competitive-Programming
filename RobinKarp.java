import java.util.Scanner;

public class RobinKarp {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		int prime = 199999991;
		System.out.print("Enter: ");
		String T = input.next();
		System.out.print("Enter: ");
		String P = input.next();
		int n = T.length();
		int m = P.length();
		int h = 1;
		int d = 10;
		int p = 0;
		int t = 0;
		for(int i = 0; i < m - 1; i++)
			h = (h * d) % prime;
		for(int i = 0; i < m; i++){
			p = (d * p + P.charAt(i)) % prime;
			t = (d *t + T.charAt(i)) % prime;
		}
		boolean match = true;
		for(int s = 0; s < n - m; s++){
			if(p == t){
				for(int i = 0; i < m; i++)
					if(P.charAt(i) != T.charAt(s + i)){
						match = false;
						break;
					}
				if(match){
					System.out.println("match found at " + (s + 1));
				}
			}
			if(s < n - m){
				t = (d * (t - ((T.charAt(s) * h) % prime)) + T.charAt(s + m)) % prime;
				if(t <= 0)
					t += prime;
			}
		}
	}
}