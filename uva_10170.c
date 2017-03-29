#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n, m, i, test ;
    while( scanf( "%lld %lld", &n, &m )==2 )
    {
        test=0 ;
        for( i=n ; test<m ; i++ )
            test+=i ;
        printf( "%lld\n", i-1 ) ;
    }
    return 0;
}
