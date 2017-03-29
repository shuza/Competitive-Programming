#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, x, a[3000], j, test ;
    while( scanf( "%d", &n )==1 )
    {
        if( n==0 )
            break ;
        for( i=0 ; i<n ; i++ )
            scanf( "%d", &a[i] ) ;
        for( i=0 ; i<n ; i++ )
            for( j=1 ; j<n ; j++ )
                if( a[j-1]>a[j] )
                {
                    test=a[j-1] ;
                    a[j-1]=a[j] ;
                    a[j]=test ;
                }
        x=0 ;
        for( i=1 ; i<n ; i++ )
            if( abs( a[i-1]-a[i] )>200 )
            {
                x=1 ;
                break ;
            }
        test=abs( a[n-1]-1422 ) ;
        test*=2 ;
        if( test>200 )
            x=1 ;
        if( x==1 )
            printf( "IMPOSSIBLE\n" ) ;
        else
            printf( "POSSIBLE\n" ) ;
    }
    return 0;
}
