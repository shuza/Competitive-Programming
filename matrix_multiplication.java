import java.util.* ;

public class matrix_multiplication {
	public static void main( String arg[] ){
		Scanner input = new Scanner( System.in ) ;
		System.out.print( "Enter row number of 1st matrix: " ) ;
		int r1 = input.nextInt() ;
		System.out.print( "Enter colum nimber of 1st matrix: " ) ;
		int c1 = input.nextInt() ;
		int i, j ;
		int m1[][] = new int[r1][c1] ;
		System.out.println( "Enter the matrix: " ) ;
		for( i = 0 ; i<r1 ; i++ )
			for( j = 0 ; j<c1 ; j++ )
				m1[i][j] = input.nextInt() ;
		System.out.print( "Enter row number of 2nd matrix: " ) ;
		int r2 = input.nextInt() ;
		System.out.print( "Enter colum number of 2nd matrix: " ) ;
		int c2 = input.nextInt() ;
		int m2[][] = new int[r2][c2] ;
		System.out.println( "Enter the matrix: " ) ;
		for( i = 0 ; i<r2 ; i++ )
			for( j = 0 ; j<c2 ; j++ )
				m2[i][j] = input.nextInt() ;
		if( c1!=r2 )
			System.out.println( "Invalid input...program tarminate..." ) ;
		else{
			int ans[][] = new int[r1][c2] ;
			int test, r, c, k ;
			for( r = 0 ; r<r1 ; r++ ){
				for( c = 0 ; c<c2 ; c++ ){
					test = 0 ;
					for( i = 0 ; i<c1 ; i++ ){
						test += m1[r][i] * m2[i][c] ;
					}
					ans[r][c] = test ;
				}
			}
			System.out.println( "Answer Matrix:" ) ;
			for( i = 0 ; i<r1 ; i++ ){
				for( j = 0 ; j<c2 ; j++ ){
					System.out.print( ans[i][j] + "\t" ) ;
				}
				System.out.println() ;
			}
		}
	}

}
