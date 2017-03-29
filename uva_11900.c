#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, n, p, q, input[31], ans, w, i ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d %d %d", &n, &p, &q ) ;
        for( i=0 ; i<n ; i++ )
            scanf( "%d", &input[i] ) ;
        ans=0 ;
        w=0 ;
        i=0 ;
        while( ans<=p && w<=q && ans<=n )
        {
            ans++ ;
            w+=input[i++] ;
        }
        if( ans>0 )
            ans-- ;
        printf( "Case %d: %d\n", count, ans ) ;
        count++ ;
    }
    return 0;
}
