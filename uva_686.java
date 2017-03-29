import java.lang.reflect.Array;
import java.util.* ;

public class uva_686 {
	public static void main( String arg[] ){
		Scanner input = new Scanner( System.in ) ;
		int max = 32770 ;
		int[] prime = new int[max] ;
		int i, j ;
		Arrays.fill( prime, 0 ) ;
		prime[1] = 1 ;
		prime[0] = 1 ;
		for( i = 4 ; i<max ; i +=2 )
			prime[i] = 1 ;
		for( i = 3 ; i<max ; i += 2 )
			if( prime[i]==0 ){
				for( j = i*i ; j<max ; j += i )
					prime[j] = 1 ;
			}
		int n ;
		while( input.hasNext() ){
			n = input.nextInt() ;
			if( n==0 )
				break ;
			int ans = 0 ;
			for( i = 2 ; i<=n/2 ; i++ ){
				if( prime[i]==0 && prime[n-i]==0 )
					ans++ ;
			}
			System.out.println( ans ) ;
		}
	}
}