#include <stdio.h>
#include <stdlib.h>

long long int fun( long int a )
{
    long long int ans=1 ;
    while( a>1 )
    {
        ans*=a ;
        a-- ;
    }
    return ans ;
}

int main()
{
    long int n ;
    long long ans ;
    while( scanf( "%ld", &n )!=EOF )
    {
        if( n<0 )
        {
            if( n%2==0 )
                printf( "Underflow!\n" ) ;
            else
                printf( "Overflow!\n" ) ;
        }
        else if( n<8 )
            printf( "Underflow!\n" ) ;
        else if( n>13 )
            printf( "Overflow!\n" ) ;
        else
        {
            ans = fun( n ) ;
            printf( "%lld\n", ans ) ;
        }
    }
    return 0;
}
