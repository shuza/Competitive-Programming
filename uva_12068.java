import java.util.* ;

public class uva_12068 {
	public static void main( String arg[] ){
		Scanner input = new Scanner( System.in ) ;
		int cas = 1, T ;
		T = input.nextInt() ;
		while( cas<=T ){
			long n = input.nextLong() ;
			long num[] = new long[(int) n] ;
			long lcm, ans = 0, gcd ;
			int i ;
			for( i = 0 ; i<n ; i++ )
				num[i] = input.nextLong() ;
			lcm = num[0] ;
			for( i = 1 ; i<n ; i++ ){
				lcm = LCM( lcm, num[i] ) ;
			}
			for( i = 0 ; i<n ; i++ ){
				ans += lcm/num[i] ;
			}
			lcm *= n ;
			gcd = GCD( ans, lcm ) ;
			ans /= gcd ;
			lcm /= gcd ;
			System.out.println( "Case " + cas + ": " + lcm + "/" + ans ) ;
			cas++ ;
		}
	}
	
	static long GCD( long a, long b ){
		long r ;
		while( a%b!=0 ){
			r = a%b ;
			a = b ;
			b = r ;
		}
		return b ;
	}
	
	static long LCM( long num1, long num2 ){
		long b ;
		b = GCD( num1, num2 ) ;
		if( num1 >num2 )
			b = ( num2/b ) * num1 ;
		else
			b = ( num1/b ) * num2 ;
		return b ;
	}
}