import java.util.* ;

public class uva_12342 {
	public static void main( String arg[] ){
		Scanner input = new Scanner( System.in ) ;
		int T, cas = 1 ;
		T = input.nextInt() ;
		while( cas<=T ){
			int n = input.nextInt() ;
			double ans ;
			if( n>1180000 ){
				n -= 1180000 ;
				ans = (double) n/4 ;
				ans += 150000 ;
			}
			else if( n>880000 ){
				n -= 880000 ;
				ans = (double) n/5 ;
				ans += 90000 ;
			}
			else if( n>480000 ){
				n -= 480000 ;
				ans = (double) n/20 ;
				ans *= 3 ;
				ans += 30000 ;
			}
			else if( n>200000 ){
				n -= 200000 ;
				ans = (double) n/10 ;
				ans += 2000 ;
			}
			else if( n>180000 )
				ans = 2000 ;
			else
				ans = 0 ;
			int tax = (int) Math.ceil( ans ) ;
			System.out.println( "Case " + cas + ": " + tax ) ;
			cas++ ;
		}
	}
}