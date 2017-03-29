import java.util.* ;

public class uva_10487 {
	public static void main( String aegs[] ){
		Scanner input = new Scanner( System.in ) ;
		int number[] ;
		int qure[] ;
		int n, i, j, q, def, ans=0, set, test, count = 1 ;
		while( input.hasNext() ){
			n = input.nextInt() ;
			if( n==0 )
				break ;
			number = new int[n] ;
			for( i = 0 ; i<n ; i++ )
				number[i] = input.nextInt() ;
			q = n*n ;
			qure = new int[q] ;
			for( i = 0, q= 0 ; i<n ; i++ ){
				for( j = i+1 ; j<n ; j++ ){
					qure[q] = number[i] + number[j] ;
					q++ ;
				}
			}
			System.out.println( "Case " + count + ":" ) ;
			n = input.nextInt() ;
			count++ ;
			for( i = 0 ; i<n ; i++ ){
				set = input.nextInt() ;
				def = 99999999 ;
				for( j = 0 ; j<q ; j++ ){
					test = qure[j] - set ;
					test = Math.abs( test ) ;
					if( test<def ){
						ans = qure[j] ;
						def = test ;
					}
				}
				System.out.println( "Closest sum to " + set + " is " + ans + "." ) ;
			}
		}
	}

}