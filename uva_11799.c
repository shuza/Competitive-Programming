#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, n, i, test, ans ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        ans=0 ;
        scanf( "%d", &n ) ;
        for( i=0 ; i<n ; i++ )
        {
            scanf( "%d", &test ) ;
            if( ans<test )
                ans=test ;
        }
        printf( "Case %d: %d\n", count, ans ) ;
        count++ ;
    }
    return 0;
}
