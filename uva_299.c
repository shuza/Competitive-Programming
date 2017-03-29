#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int T, N, a[50], test, i, j, ans ;
    scanf( "%u", &T ) ;
    while( T>0 )
    {
        ans=0 ;
        scanf( "%u", &N ) ;
        for( i=0 ; i<N ; i++ )
            scanf("%u", &a[i] ) ;
        for( i=0 ; i<N ; i++ )
            for( j=1 ; j<N ; j++ )
                if( a[j-1]>a[j] )
                {
                    test=a[j-1] ;
                    a[j-1]=a[j] ;
                    a[j]=test ;
                    ans++ ;
                }
        printf( "Optimal train swapping takes %u swaps.\n", ans ) ;
        T-- ;
    }
    return 0;
}
