#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int N, test, x ;
    while( scanf( "%llu", &N )==1 )
    {
        if( N==0 )
            break ;
        x=N*10/9 ;
        if( x%10==0 )
            printf( "%llu %llu\n", x-1, x ) ;
        else
            printf( "%llu\n", x ) ;
    }
    return 0;
}
