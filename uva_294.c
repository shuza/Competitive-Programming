#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int L, U, test, i, D, j, k, sq ;
    int ans, x, N ;
    scanf( "%d", &N ) ;
    while( N>0 )
    {
        scanf( "%ld %ld", &L, &U ) ;
        ans=0 ;
        D=L ;
        for( i=L ; i<=U ; i++ )
        {
            test=0 ;
            sq=sqrt( i ) ;
            for( j=2 ; j<=sq ; j++ )
                if( i%j==0 )
                    test+=2 ;
            if( sq*sq==i )
                test-- ;
            test+=2 ;
            if( test>ans )
            {
                ans=test ;
                D=i ;
            }
        }
        printf( "Between %ld and %ld, %ld has a maximum of %d divisors.\n", L, U, D, ans ) ;
        N-- ;
    }
    return 0;
}
