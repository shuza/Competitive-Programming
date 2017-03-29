import java.util.* ;

public class Kunt_Mprris_Partt {
	
	static int automation[] ;
	
	public static void main( String[] arg ){
		Scanner input = new Scanner( System.in ) ;
		System.out.print( "Enter the text: " ) ;
		String T = input.next() ;
		System.out.print( "Enter the pattern: " ) ;
		String P = input.next() ;
		int m = P.length() ;
		int n = T.length() ;
		automation = new int[m] ;
		automation[0] = 0 ;
		int q, k, i ;
		k = 0 ;
		for( q = 1 ; q<m ; q++ ){
			while( k>0 && P.charAt(k)!=P.charAt(q) )
				k = automation[k] ;
			if( P.charAt(k)==P.charAt(q) )
				k++ ;
			automation[q] = k ;
		}
		q = 0 ;
		for( i = 0 ; i<n ; i++ ){
			while( q>0 && P.charAt(q)!=T.charAt(i) )
				q = automation[q] ;
			if( P.charAt(q)==T.charAt(i) )
				q++ ;
			if( q==m ){
				System.out.println( "Pattern occurs with shift " + (i-m+1) ) ;
				break ;
			}
		}
		System.out.println( "\tend...." ) ;
	}
}