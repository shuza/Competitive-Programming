    /*********     ternary   convertion    ********/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x ;
    int a[65], i ;
    while( scanf( "%lld", &x )==1 )
    {
        if( x<0 )
            break ;
        if( x==0 )
        {
            printf( "0\n" ) ;
            continue ;
        }
        for( i=0 ; x!=0 ; i++ )
        {
            a[i]=x%3 ;
            x/=3 ;
        }
        for( i-- ; i>=0 ; i-- )
            printf( "%d", a[i] ) ;
        printf( "\n" ) ;
    }
    return 0;
}
