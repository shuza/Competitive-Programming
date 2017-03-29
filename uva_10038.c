#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[3002], def[3002], i, c, b ;
    while( scanf( "%d", &n )==1 )
    {
        if( n<=0 )
        {
            printf( "Not jolly\n" ) ;
            continue ;
        }
        for( i=0 ; i<n ; i++ )
        {
            scanf( "%d", &a[i] ) ;
            def[i]=0 ;
        }
        for( i=1 ; i<n ; i++ )
        {
            b=abs( a[i-1]-a[i] ) ;
            def[b]=b ;
        }
        b=0 ;
        for( i=1 ; i<n ; i++ )
            if( def[i]!=i )
            {
                b=1 ;
                break ;
            }
        if( b==1 )
            printf( "Not jolly\n" ) ;
        else
            printf( "Jolly\n" ) ;
    }
    return 0;
}
