#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, n, i, mile, juice, test ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d", &n ) ;
        mile=0 ;
        juice=0 ;
        for( i=0 ; i<n ; i++ )
        {
            scanf( "%d", &test ) ;
            mile+=test/30 +1 ;
            juice+=test/60 +1 ;
        }
        mile*=10 ;
        juice*=15 ;
        if( mile<juice )
            printf( "Case %d: Mile %d\n", count, mile ) ;
        else if( juice<mile )
            printf( "Case %d: Juice %d\n", count, juice ) ;
        else
            printf( "Case %d: Mile Juice %d\n", count, mile ) ;
        count++ ;
    }
    return 0;
}
