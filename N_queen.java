import java.util.Scanner;

public class N_queen {
	static int bordSize;
	static boolean[][] queenPresent;
	static boolean exit;
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the Bord size: ");
		bordSize = input.nextInt();
		queenPresent = new boolean[bordSize][bordSize];
		if(placeQueen(0))
			showBord();
		else
			System.out.println("Can't solve...");
	}

	private static void showBord() {
		for(int i = 0; i < bordSize; i++){
			for(int c = 0; c < bordSize; c++)
				if(queenPresent[i][c])
					System.out.print("Q");
				else
					System.out.print(".");
			System.out.println();
		}
	}

	private static boolean placeQueen(int row) {
		if(row == bordSize)
			return true;
		int colum = 0;
		boolean seccessful = false;
		while(colum < bordSize && !seccessful){
			if(!canPlace(row, colum))
				colum++;
			else{
				queenPresent[row][colum] = true;
				seccessful = placeQueen(row + 1);
				if(!seccessful){
					queenPresent[row][colum] = false;
					colum++;
				}
			}
		}
		return seccessful;
	}

	private static boolean canPlace(int row, int colum) {
		for(int i = 0; i < row; i++)
			if(queenPresent[i][colum])
				return false;
		for(int i = 1; i <= row; i++){
			if(colum - i < 0)
				break;
			if(queenPresent[row - i][colum - i])
				return false;
		}
		for(int i = 1; i <= row; i++){
			if(colum + i >= bordSize)
				break;
			if(queenPresent[row- i][colum + i])
				return false;
		}
		return true;
	}
}