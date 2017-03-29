import java.util.Scanner;

public class Backtracking {
	static int bordSize;
	static boolean[][] tabel;
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the bordsize: ");
		bordSize = input.nextInt();
		tabel = new boolean[bordSize][bordSize];
		if(placeQueen(0))
			showBord();
		else
			System.out.println("Can't place...");
	}
	private static boolean placeQueen(int row) {
		if(row == bordSize)
			return true;
		int col = 0;
		boolean seccessful = false;
		while(col < bordSize && !seccessful){
			if(canPlace(row, col)){
				tabel[row][col] = true;
				seccessful = placeQueen(row + 1);
				if(!seccessful){
					tabel[row][col] = false;
					col++;
				}
			}
			else
				col++;
		}
		return seccessful;
	}
	private static boolean canPlace(int row, int col) {
		for(int i = 0; i < row; i++)
			if(tabel[i][col])
				return false;
		for(int i = 1; i <= row && col - i >= 0; i++)
			if(tabel[row - i][ col - i])
				return false;
		for(int i = 0; i <= row && col + i < bordSize; i++)
			if(tabel[row - i][col + i])
				return false;
		return true;
	}
	private static void showBord() {
		for(int i = 0; i < bordSize; i++){
			for(int j = 0; j < bordSize; j++)
				if(tabel[i][j])
					System.out.print("Q");
				else
					System.out.print("+");
			System.out.println();
		}
	}
}