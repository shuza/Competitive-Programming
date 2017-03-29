#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double area, pi, r, n ;
    pi = 4 * acos(0) ;
    while( scanf( "%lf %lf", &r, &n )!=EOF )
    {
        area = r*r*sin( pi/n ) / 2 ;
        area *= n ;
        printf( "%.3lf\n", area ) ;
    }
    return 0;
}
