import java.util.Scanner;

public class uva_160 {
	public static void main(String[] arg){
		int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			int N = input.nextInt();
			if(N == 0)
				break;
			int i, test = 1, m = N;
			System.out.printf("%3d! =", N);
			int[] ans = new int[25];
			while(N > 1){
				test *= N;
				for(i = 0; i < 25; i++){
					while(test % prime[i] == 0){
						ans[i]++;
						test /= prime[i];
					}
				}
				N--;
			}
			for(i = 0; i < 25 && prime[i] <= m; i++){
				if(i == 15)
					System.out.printf("\n%6c", ' ');
				System.out.printf("%3d", ans[i]);
			}
			System.out.println();
		}
	}
}