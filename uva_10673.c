#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int x, k, p, q, a, b ;
    int T ;
    long double c ;
    scanf( "%d", &T ) ;
    while( T>0 )
    {
        scanf( "%ld %ld", &x, &k ) ;
        a=x/k ;
        c=( double ) x/k ;
        b=ceil( c ) ;
        k=0 ;
        p=0 ;
        while( k!=x )
        {
            q=( x-a*p )/b ;
            k=p*a+q*b ;
            p++ ;
        }
        printf( "%ld %ld\n", p-1, q ) ;
        T-- ;
    }
    return 0;
}
