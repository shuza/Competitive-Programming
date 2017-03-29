import java.util.* ;

public class uva_11000 {
	public static void main( String[] arg ){
		Scanner input = new Scanner( System.in ) ;
		while( input.hasNext() ){
			int N = input.nextInt() ;
			if( N==-1 )
				break ;
			int m, f, c, i ;
			m = 0 ;
			f =  1 ;
			for( i = 0 ; i<N ; i++ ){
				c = m ;
				m += f ;
				f = c ;
			}
			System.out.println( m + " " + ( m+f ) ) ;
		}
	}
}