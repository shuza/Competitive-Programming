import java.util.* ;

public class uva_11530 {
	public static void main( String[] arg ){
		Scanner input = new Scanner( System.in ) ;
		String str = input.nextLine() ;
		int T = Integer.parseInt( str ) ;
		int cas = 1 ;
		while( cas<=T ){
			str = input.nextLine() ;
			int ans = 0 ;
			for( int i = 0 ; i<str.length() ; i++ ){
				ans += fun( str.charAt( i ) ) ;
			}
			System.out.println( "Case #" + cas + ": " + ans ) ;
			cas++ ;
		}
	}
	
	static int fun( char c ){
		if( c=='a' || c=='d' || c=='g' || c=='j' || c=='m' || c=='p' || c=='t' || c=='w' || c==' ' )
			return 1 ;
		if( c=='b' || c=='e' || c=='h' || c=='k' || c=='n' || c=='q' || c=='u' || c=='x' )
			return 2 ;
		if( c=='c' || c=='f' || c=='i' || c=='l' || c=='o' || c=='r' || c=='v' || c=='y' )
			return 3 ;
		return 4 ;
	}
}