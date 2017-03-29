#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int a, b, c ;
    int T, ans ;
    scanf( "%d", &T ) ;
    while( T>0 )
    {
        scanf( "%lu", &a ) ;
        ans=0 ;
        b=0 ;
        while( ans<=1000 )
        {
            b=0 ;
            c=a ;
            while( c!=0 )
            {
                b=b*10+( c%10) ;
                c/=10 ;
            }
            if( a==b )
                break ;
            a+=b ;
            ans++ ;
        }
        printf( "%d %lu\n", ans, a ) ;
        T-- ;
    }
    return 0;
}
