#include <stdio.h>
#include <stdlib.h>

int main()
{
    char binary[32] ;
    long int I, i, a, ans ;
    while( scanf( "%ld", &I )==1 )
    {
        if( I==0 )
            break ;
        ans=0 ;
        i=0 ;
        while( I!=0 )
        {
            a=I%2 ;
            if( a==1 )
                ans++ ;
            I/=2 ;
            binary[i++]=( char ) ( a+48 ) ;
        }
        printf( "The parity of " ) ;
        i-- ;
        while( i>=0 )
            printf( "%c", binary[i--] ) ;
        printf( " is %d (mod 2).\n", ans ) ;
    }
    return 0;
}
