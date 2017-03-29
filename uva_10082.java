import java.util.Scanner;

public class uva_10082 {
	public static void main(String[] arg){
		String row0 = "`1234567890-=";
		String row1 = "QWERTYUIOP[]";
		String row2 = "ASDFGHJKL;'";
		String row3 = "ZXCVBNM,./";
		boolean line = false;
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String test = input.nextLine();
			int n = test.length();
			int j, i;
			for(i = 0; i < n; i++){
				j = row0.indexOf(test.charAt(i));
				if(j != -1){
					System.out.print(row0.charAt(j - 1));
					continue;
				}
				j = row1.indexOf(test.charAt(i));
				if(j != -1){
					System.out.print(row1.charAt(j - 1));
					continue;
				}
				j = row2.indexOf(test.charAt(i));
				if(j != -1){
					System.out.print(row2.charAt(j - 1));
					continue;
				}
				j = row3.indexOf(test.charAt(i));
				if(j != -1){
					System.out.print(row3.charAt(j - 1));
					continue;
				}
				if(test.charAt(i) == ' '){
					System.out.print(" ");
					continue;
				}
				j = (int) test.charAt(i);
				if(j == 92){
					System.out.print("]");
					continue;
				}
				System.out.print(test.charAt(i));
			}
			System.out.println();
		}
	}
}