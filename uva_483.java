import java.util.Scanner;

public class uva_483 {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			String str = input.nextLine();
			int l = str.length();
			int i;
			for(i = 0; i < l; i++){
				if(str.charAt(i) == ' '){
					int j = i - 1;
					while(j >= 0 && str.charAt(j) != ' '){
						System.out.print(str.charAt(j));
						j--;
					}
					System.out.print(" ");
				}
			}
			for(i-- ; i >= 0 && str.charAt(i) != ' '; i--)
				System.out.print(str.charAt(i));
			System.out.println();
		}
	}
}