#include <stdio.h>
#include <stdlib.h>

long long int fun( long long int a )
{
    long long int i, ans=0 ;
    for( i = 1 ; i<a ; i++ )
        if( a%i==0 )
        {
            ans += i ;
            if( ans>a )
                break ;
        }
    return ans ;
}

int main()
{
    long long int num[10000], i=0, j, k, sum ;
    while( 1 )
    {
        scanf( "%lld", &num[i] ) ;
        if( num[i]==0 )
            break ;
        i++ ;
    }
    printf( "PERFECTION OUTPUT\n" ) ;
    for( j=0 ; j<i ; j++ )
    {
        sum = fun( num[j] ) ;
        if( sum==num[j] )
            printf( "%5lld  PERFECT\n", num[j] ) ;
        else if( sum>num[j] )
            printf( "%5lld  ABUNDANT\n", num[j] ) ;
        else
            printf( "%5lld  DEFICIENT\n", num[j] ) ;
    }
    printf( "END OF OUTPUT\n" ) ;
    return 0;
}
