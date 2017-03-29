import java.util.* ;

public class uva_401 {
	public static void main( String[] arg ){
		Scanner input = new Scanner( System.in ) ;
		while( input.hasNext() ){
			String str = input.next() ;
			int i, j, l = str.length() ;
			j = l-1 ;
			boolean palindorm = true ;
			for( i = 0 ; i<l ; i++, j-- )
				if( str.charAt( i )!=str.charAt( j ) ){
					palindorm = false ;
					break ;
				}
			j = l-1 ;
			char c ;
			boolean mirror = true ;
			for( i = 0 ; i<l ; i++, j-- ){
				c = str.charAt( i ) ;
				c = REVERSE( c ) ;
				if( c!=str.charAt( j ) ){
					mirror = false ;
					break ;
				}
			}
			if( palindorm && mirror )
				System.out.println( str + " -- is a mirrored palindrome.\n" ) ;
			else if( mirror )
				System.out.println( str + " -- is a mirrored string.\n" ) ;
			else if( palindorm )
				System.out.println( str + " -- is a regular palindrome.\n" ) ;
			else
				System.out.println( str + " -- is not a palindrome.\n" ) ;
		}
	}
	
	static char REVERSE( char c ){
		if( c=='E' )
			return '3' ;
		if( c=='J' )
			return 'L' ;
		if( c=='L' )
			return 'J' ;
		if( c=='S' )
			return '2' ;
		if( c=='Z' )
			return '5' ;
		if( c=='2' )
			return 'S' ;
		if( c=='3' )
			return 'E' ;
		if( c=='5' )
			return 'Z' ;
		if( c=='A' || c=='H' || c=='I' || c=='M' || c=='O' || c=='T' || c=='U' || c=='V' || c=='W' || c=='X' || c=='Y' || c=='1' || c=='8' )
			return c ;
		return '?' ;
	}
}