#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ans ;
    while( scanf( "%d", &n)==1 )
    {
        if( n==0 )
            break ;
        ans=0 ;
        while( n>=3 )
        {
            ans+=n/3 ;
            n=( n/3 )+( n%3 ) ;
        }
        if( n==2 )
            ans++ ;
        printf( "%d\n", ans ) ;
    }
    return 0;
}
