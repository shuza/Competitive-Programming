import java.util.* ;

public class uva_10019 {
	public static void main( String args[] ){
		Scanner input = new Scanner( System.in ) ;
		int T = input.nextInt() ;
		while( T>0 ){
			int n, b1, b2, i ;
			n = input.nextInt() ;
			b1 = binary( n ) ;
			System.out.print( b1 ) ;
			b2 = 0 ;
			for( i = 0 ; n!=0 ; i++ ){
				b1 = n%10 ;
				b2 += b1 * Math.pow( 16, i ) ;
				n /= 10 ;
			}
			b2 = binary( b2 ) ;
			System.out.println( " " + b2 ) ;
			T-- ;
		}
	}
	
	public static int binary( int n ){
		int one = 0 ;
		while( n!=0 ){
			if( n%2==1 )
				one++ ;
			n /= 2 ;
		}
		return one ;
	}

}
