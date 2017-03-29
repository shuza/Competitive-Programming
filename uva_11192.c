#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[101] ;
    int n, i, l, j, k, count ;
    while( scanf( "%d", &n)==1 )
    {
        if( n==0 )
            break ;
        scanf( "%s", input ) ;
        l=strlen( input ) ;
        j=l/n ;
        i=1 ;
        while( i<=n )
        {
            l=(i-1)*n ;
            count=0 ;
            for( k=i*j-1 ; count<j ; count++ )
            {
                printf( "%c", input[k] ) ;
                k-- ;
            }
            i++ ;
        }
        printf( "\n" ) ;
    }
    return 0;
}
