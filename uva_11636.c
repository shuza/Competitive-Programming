#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=1, test, input, i ;
    while( scanf( "%d", &input )==1 )
    {
        if( input<0 )
            break ;
        test=1 ;
        for( i=1 ; test<input ; i++ )
            test*=2 ;
        printf( "Case %d: %d\n", count, i-1 ) ;
        count++ ;
    }
    return 0;
}
