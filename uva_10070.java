import java.util.Scanner;

public class uva_10070 {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		boolean line = false;
		while(input.hasNext()){
			String str = input.next();
			if(line)
				System.out.println();
			boolean ordinary = true;
			boolean leap = false;
			leap = leap_year(str);
			if(leap){
				System.out.println("This is leap year.");
				ordinary = false; 
			}
			boolean result = false;
			result = huluculu(str);
			if(result){
				System.out.println("This is huluculu festival year.");
				ordinary = false;
			}
			if(leap){
				result = bulukulu(str);
				if(result)
					System.out.println("This is bulukulu festival year.");
			}
			if(ordinary)
				System.out.println("This is an ordinary year.");
			line = true;
		}
	}

	private static boolean bulukulu(String str) {
		int l, i, sum = 0;
		l = str.length();
		for(i = 0; i < l; i++){
			sum = sum * 10 + str.charAt(i) - '0';
			sum %= 55;
		}
		if(sum == 0)
			return true;
		return false;
	}

	private static boolean huluculu(String str) {
		int l, i, sum = 0;
		l = str.length();
		for(i = 0; i < l; i++){
			sum = sum * 10 + str.charAt(i) - '0';
			sum %= 15;
		}
		if(sum == 0)
			return true;
		return false;
	}

	private static boolean leap_year(String str) {
		int l, sum_100 = 0, i, sum_400 = 0, sum_4 = 0;
		l = str.length();
		for(i = 0; i < l; i++){
			sum_100 = sum_100 * 10 + str.charAt(i) - '0';
			sum_100 %= 100;
			sum_400 = sum_400 * 10 + str.charAt(i) - '0';
			sum_400 %= 400;
			sum_4 = sum_4 * 10 + str.charAt(i) - '0';
			sum_4 %= 4;
		}
		if(sum_400 == 0 || (sum_4 == 0 && sum_100 != 0))
			return true;
		return false;
	}
}