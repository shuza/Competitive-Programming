#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, n, p, k, ans ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d %d %d", &n, &k, &p ) ;
        ans=( n+k+p )%n ;
        if( ans==0 )
            ans=n ;
        printf( "Case %d: %d\n", count, ans ) ;
        count++ ;
    }
    return 0;
}
