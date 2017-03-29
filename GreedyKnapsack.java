import java.util.Scanner;

public class GreedyKnapsack {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the element number: ");
		int N = input.nextInt();
		System.out.print("Enter the weight: ");
		int i, j;
		int[] w = new int[N];
		for(i = 0; i < N; i++)
			w[i] = input.nextInt();
		System.out.print("Enter the profit: ");
		int[] p = new int[N];
		for(i = 0; i < N; i++)
			p[i] = input.nextInt();
		double[] x = new double[N];
		for(i = 0; i < N; i++)
			x[i] = (double) p[i] / w[i];
		for(i = 0; i < N; i++)
			for(j = 1; j < N; j++)
				if(x[j - 1] < x[j]){
					int test = p[j - 1];
					p[j - 1] = p[j];
					p[j] = test;
					test = w[j - 1];
					w[j - 1] = w[j];
					w[j] = test;
					double z = x[j -1];
					x[j - 1] = x[j];
					x[j] = z;
				}
		System.out.print("Enter the max weight: ");
		for(i = 0; i < N; i++){
			System.out.println(w[i] + "\t" + p[i]);
		}
		int weight = input.nextInt();
		double profit = 0;
		for(i = 0; weight > 0; i++){
			if(weight >= w[i]){
				profit += p[i];
				weight -= w[i];
				System.out.println(w[i]);
			}
			else{
				profit += (double) p[i] * weight / w[i];
				break;
			}
		}
		System.out.println("Maximum profit = " + profit);
	}
}