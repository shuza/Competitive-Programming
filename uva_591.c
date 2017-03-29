#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=1, n, a[50], i, ans, avg ;
    while( scanf( "%d", &n )==1 )
    {
        if( n==0 )
            break ;
        avg=0 ;
        for( i=0 ; i<n ; i++ )
        {
            scanf( "%d", &a[i] ) ;
            avg+=a[i] ;
        }
        avg/=n ;
        ans=0 ;
        for( i=0 ; i<n ; i++ )
            ans+=abs( avg-a[i] ) ;
        ans/=2 ;
        printf( "Set #%d\nThe minimum number of moves is %d.\n\n", T, ans ) ;
        T++ ;
    }
    return 0;
}
