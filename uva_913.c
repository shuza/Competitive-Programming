#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int ans ;
    unsigned long int N, n,term ;
    while( scanf( "%lu", &N )==1 )
    {
        n=( N-1 )/2 + 1 ;
        term=( N+1 )/2 ;
        term*=n ;
        ans=1+( term-1 )*2 ;
        ans+=( ans-2 )+( ans-4 ) ;
        printf( "%llu\n", ans ) ;
    }
    return 0;
}
