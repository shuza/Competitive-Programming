#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ans, test, b ;
    while( scanf( "%d", &n )==1 )
    {
        ans=n ;
        b=n ;
        test=n+1 ;
        while( n>=3 )
        {
            ans+=n/3 ;
            n=( n/3 )+( n%3 ) ;
        }
        while( test>=3 )
        {
            b+=test/3 ;
            test=( test/3 )+( test%3 ) ;
        }
        if( b>ans )
            ans=b ;
        printf( "%d\n", ans ) ;
    }
    return 0;
}
