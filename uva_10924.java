import java.util.* ;

public class uva_10924 {
	public static void main( String arg[] ){
		Scanner input = new Scanner( System.in ) ;
		while( input.hasNext() ){
			String str  = input.next() ;
			int i, sum = 0 ;
			char c ;
			for( i = 0 ; i<str.length() ; i++ ){
				c = str.charAt( i ) ;
				if( c>='A' && c<='Z' )
					sum += (int) c%64 + 26 ;
				else
					sum += (int) c%96 ;
			}
			boolean prime = isprime( sum ) ;
			if( prime )
				System.out.println( "It is a prime word." ) ;
			else
				System.out.println( "It is not a prime word." ) ;
		}
	}
	
	static boolean isprime( int num ){
		int l, i ;
		l = (int) Math.sqrt( num ) ;
		for( i = 2 ; i<=l ; i++ )
			if( num%i==0 )
				return false ;
		return true ;
	}

}
