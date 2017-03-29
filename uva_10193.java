import java.util.Scanner;

public class uva_10193 {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		int N, cas = 1;
		N = input.nextInt();
		while(cas <= N){
			String str = input.next();
			int num1 = Decmail(str);
			str = input.next();
			int num2 = Decmail(str);
			num1 = GCD(num1, num2);
			if(num1 > 1)
				System.out.println("Pair #" + cas+ ": All you need is love!");
			else
				System.out.println("Pair #" + cas + ": Love is not all you need!");
			cas++;
		}
	}

	private static int GCD(int num1, int num2) {
		int r;
		while(num1 % num2 != 0){
			r = num1 % num2;
			num1 = num2;
			num2 = r;
		}
		return num2;
	}

	private static int Decmail(String str) {
		int base, test, ans, l;
		ans = 0;
		base = 1;
		l = str.length() - 1;
		while(l >= 0){
			test = (int) str.charAt(l) - '0';
			ans += test * base;
			base *= 2;
			l--;
		}
		return ans;
	}
}