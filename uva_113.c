#include <stdio.h>
#include <stdlib.h>

int main()
{
    double k, n, p ;
    while( scanf( "%lf %lf", &n, &p )==2 )
    {
        k = pow( p, 1/n ) ;
        printf( "%.0lf\n", k ) ;
    }
    return 0;
}
