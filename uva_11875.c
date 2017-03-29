#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, mem, input[12], big, small, ans, i ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d", &mem ) ;
        for( i=0 ; i<mem ; i++ )
            scanf( "%d", &input[i] ) ;
        ans=mem/2 ;
        printf( "Case %d: %d\n", count, input[ans] ) ;
        count++ ;
    }
    return 0;
}
