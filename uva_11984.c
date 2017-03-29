#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, a, b ;
    double ans ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d %d", &a, &b ) ;
        ans=( double ) 9*a/5 ;
        ans+=32+b ;
        ans=( double ) ( ans-32 )*5/9 ;
        printf( "Case %d: %.2lf\n", count, ans ) ;
        count++ ;
    }
    return 0;
}
