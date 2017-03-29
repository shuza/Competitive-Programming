import java.util.* ;

public class uva_10190 {
	public static void main( String args[] ){
		Scanner input = new Scanner( System.in ) ;
		int n, m ;
		while( input.hasNext() ){
			n = input.nextInt() ;
			m = input.nextInt() ;
			if( n<m || m<2){
				System.out.println( "Boring!" ) ;
				continue ;
			}
			int arr[] = new int[42000000] ;
			int ans = 1, i = 1, j ;
			arr[0] = n ;
			while( n%m==0 ){
				arr[i] = n/m ;
				n /= m ;
				i++ ;
			}
			if( n!=1 )
				System.out.println( "Boring!" ) ;
			else{
				for( j = 0 ; j<i-1 ; j++ )
					System.out.print( arr[j] + " " ) ;
				System.out.println( arr[j] ) ;
			}
		}
	}
}