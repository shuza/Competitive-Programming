#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    unsigned int a, b, c ;
    long long int plus, test ;
    scanf( "%d", &T ) ;
    for( i = 1 ; i <= T ; i++ )
    {
        scanf("%d %d %d", &a, &b, &c ) ;
        if( a > b && a > c )
        {
            test = a*a ;
            plus = b*b + c*c ;
        }
        else if( b > a && b > c )
        {
            test = b*b ;
            plus = a*a + c*c ;
        }
        else
        {
            plus = a*a + b*b ;
            test = c*c ;
        }
        if( plus == test )
            printf( "Case %d: yes\n", i ) ;
        else
            printf( "Case %d: no\n", i ) ;
    }
    return 0;
}
