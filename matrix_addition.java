import java.util.Scanner;

public class matrix_addition {
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		while(true){
			System.out.print("Enter the 1st matrix row and colum: ");
			int r1 = input.nextInt();
			int c1 = input.nextInt();
			System.out.print("Enter 1st matrix's element: ");
			int[][] matrix1 = new int[r1][c1];
			int i, j;
			for(i = 0; i < r1; i++)
				for(j = 0; j < c1; j++)
					matrix1[i][j] = input.nextInt();
			System.out.print("Enter 2nd matrix row nad colum: ");
			int r2 = input.nextInt();
			int c2 = input.nextInt();
			int[][] matrix2 = new int[r2][c2];
			System.out.print("Enter 2nd matrix's element: ");
			for(i = 0; i < r2; i++)
				for(j = 0; j < c2; j++)
					matrix2[i][j] = input.nextInt();
			if(r1 == r2 && c1 == c2){
				add_matrix(matrix1, r1, c1, matrix2);
				break;
			}
			System.out.println("Invalid input....");
		}
	}

	private static void add_matrix(int[][] matrix1, int r1, int c1,
			int[][] matrix2) {
		int i, j;
		for(i = 0; i < r1; i++){
			for(j = 0; j < c1; j++)
				System.out.print((matrix1[i][j] + matrix2[i][j]) + "   ");
			System.out.println();
		}
	}
}