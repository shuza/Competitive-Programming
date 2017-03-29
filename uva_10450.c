#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a , b, c ;
    int T, count=1, n, i ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d", &n ) ;
        a=1 ;
        b=2 ;
        c=2 ;
        for( i=2 ; i<=n ; i++ )
        {
            c=a+b ;
            a=b ;
            b=c ;
        }
        printf( "Scenario #%d:\n%lld\n\n", count, c ) ;
        count++ ;
    }
    return 0;
}
