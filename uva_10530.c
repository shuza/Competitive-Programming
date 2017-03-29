#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test, low=0, high=11 ;
    char c[10], d[10] ;
    while( scanf( "%d", &test )==1 )
    {
        if( test==0 )
            break ;
        scanf( "%s %s", c, d ) ;
        if( c[0]=='r' )
        {
            if( low < test && test < high && high > low )
                printf( "Stan may be honest\n" ) ;
            else
                printf( "Stan is dishonest\n" ) ;
            low=0 ;
            high=11 ;
        }
        else if( d[0]=='h' && test<high )
            high=test ;
        else if( d[0]=='l' && test>low )
            low=test ;
    }
    return 0;
}
