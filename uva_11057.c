#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a[10000], x, y, def ;
    int i, j, n, M ;
    while( scanf( "%d", &n)!=EOF )
    {
        for( i=0 ; i<n ; i++ )
            scanf( "%ld", &a[i] ) ;
        scanf( "%d", &M ) ;
        def=1000099 ;
        for( i=0 ; i<n ; i++ )
        {
            for( j=i+1 ; j<n ; j++ )
                if( a[i]+a[j]==M && def>abs( a[i]-a[j] ) )
                {
                    if( a[i]>a[j] )
                    {
                        x=a[j] ;
                        y=a[i] ;
                    }
                    else
                    {
                        x=a[i] ;
                        y=a[j] ;
                    }
                    def=abs( a[i]-a[j] ) ;
                }
        }
        printf( "Peter should buy books whose prices are %ld and %ld.\n\n", x, y ) ;
    }
    return 0;
}
