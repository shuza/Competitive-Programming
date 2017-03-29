#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, input[1000], i, j, test, count ;
    while( scanf( "%d", &N )!=EOF )
    {
        for( i=0 ; i<N ; i++ )
            scanf( "%d", &input[i] ) ;
        count=0 ;
        for( i=0 ; i<N ; i++ )
            for( j=1 ; j<N ; j++ )
                if( input[j-1]>input[j] )
                {
                    test=input[j-1] ;
                    input[j-1]=input[j] ;
                    input[j]=test ;
                    count++ ;
                }
        printf( "Minimum exchange operations : %d\n", count ) ;
    }
    return 0;
}
