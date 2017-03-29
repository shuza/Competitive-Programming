#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, a[10][10], count=1, n, ans, y ;
    while( scanf( "%d", &x )==1 )
    {
        if( x==0 )
            break ;
        for( i=0 ; i<x ; i++ )
            for( j=0 ; j<x ; j++ )
                scanf( "%d", &a[i][j] ) ;
        printf( "Case %d:", count ) ;
        y=0 ;
        while( x>0 )
        {
            ans=0 ;
            for( i=0 ; i<x ; i++ )
            {
                for( j=0 ; j<x ; j++ )
                {
                    if( i==0 || i==x-1 )
                        ans+=a[i+y][j+y] ;
                    else if( j==0 || j==x-1 )
                        ans+=a[i+y][j+y] ;
                }
            }
            printf( " %d", ans ) ;
            x-=2 ;
            y++ ;
        }
        printf( "\n" ) ;
        count++ ;
    }
    return 0;
}
