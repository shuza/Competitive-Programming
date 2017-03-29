import java.util.Scanner;

public class uva_750 {
	static int solveRow, solveCol, boreSize, ansNo;
	static boolean[][] queenPresent;
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		boreSize = 8;
		boolean line = false;
		int count = input.nextInt();
		while(count > 0){
			if(line)
				System.out.println();
			System.out.println("SOLN       COLUMN");
			System.out.println(" #      1 2 3 4 5 6 7 8");
			System.out.println();
			solveRow = input.nextInt();
			solveCol = input.nextInt();
			queenPresent = new boolean[boreSize][boreSize];
			ansNo = 1;
			queenPlace(0);
			count--;
			line = true;
		}
	}
	private static boolean queenPlace(int col) {
		if(col == boreSize){
			if(queenPresent[solveRow - 1][solveCol - 1]){
				System.out.printf("%2d      ", ansNo++);
				showBord();
			}
			return false;
		}
		int row = 0;
		boolean seccessful = false;
		while(row < boreSize && !seccessful){
			if(!canPlace(row, col))
				row++;
			else{
				queenPresent[row][col] = true;
				seccessful = queenPlace(col + 1);
				if(!seccessful){
					queenPresent[row][col] = false;
					row++;
				}else if(col + 1 == boreSize && seccessful){
					queenPresent[row][col] = false;
				}
			}
		}
		return seccessful;
	}
	private static boolean canPlace(int row, int col) {
		for(int r = 0; r < boreSize; r++)
			if(queenPresent[r][col] && r != row)
				return false;
		for(int c = 0; c < col; c++)
			if(queenPresent[row][c])
				return false;
		for(int x = 1; x <= col; x++){
			if(row - x < 0)
				break;
			if(queenPresent[row - x][col - x])
				return false;
		}
		for(int x = 1; x <= col; x++){
			if(row + x >= boreSize)
				break;
			if(queenPresent[row + x][col - x])
				return false;
		}
		return true;
	}
	private static void showBord() {
		for(int c = 0; c < boreSize; c++){
			for(int r = 0; r < boreSize; r++)
				if(queenPresent[r][c]){
					System.out.print((r + 1));
					if(c != boreSize - 1)
						System.out.print(" ");
				}
		}
		System.out.println();
	}
}