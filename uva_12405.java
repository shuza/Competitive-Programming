import java.util.* ;

public class uva_12405 {
	public static void main( String aeg[] ){
		Scanner input = new Scanner( System.in ) ;
		int cas = 1 ;
		int T = input.nextInt() ;
		while( cas <= T ){
			int n = input.nextInt() ;
			String str = input.next() ;
			int i, count = 0, ans = 0 ;
			for( i = 0 ; i<n ; i++ ){
				if( str.charAt( i ) == '.' )
					count++ ;
				else{
					ans += count/3 ;
					if( count % 3 == 1 && i+1<n && str.charAt( i+1 ) == '.' ){
						ans++ ;
						i++ ;
					}
					else if( count % 3 != 0 )
						ans++ ;
					count = 0 ;
				}
			}
			ans += count/3 ;
			if( count % 3 != 0 )
				ans++ ;
			System.out.println( "Case " + cas + ": " + ans ) ;
			cas++ ;
		}
	}
}