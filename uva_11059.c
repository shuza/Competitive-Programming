#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int ans, now ;
    int T=1, a[20], n, i, j ;
    while( scanf( "%d", &n )!=EOF )
    {
        for( i=0 ; i<n ; i++ )
            scanf( "%d", &a[i] ) ;
        ans=0 ;
        for( i=0 ; i<n ; i++ )
            for( now=1, j=i ; j<n ; j++ )
            {
                now*=a[j] ;
                if( now>ans )
                ans=now ;
            }
        printf( "Case #%d: The maximum product is %lld.\n\n", T, ans ) ;
        T++ ;
    }
    return 0;
}
