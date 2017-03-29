#include <stdio.h>
#include <stdlib.h>

void binary( int a )
{
    int ans[13]={0},  i=0 ;
    while( a!=0 )
    {
        ans[i]=a%2 ;
        a/=2 ;
        i++ ;
    }
    i=12 ;
    while( i>=0 )
    {
        printf( "%d", ans[i] ) ;
        i-- ;
    }
}

int main()
{
    int a, b, N, ans ;
    char c ;
    scanf( "%d", &N ) ;
    while( N>0 )
    {
        scanf( "%X %c %X", &a, &c, &b ) ;
        binary( a ) ;
        if( c=='+' )
        {
            printf( " + " ) ;
            ans=a+b ;
        }
        else
        {
            printf( " - " ) ;
            ans=a-b ;
        }
        binary( b ) ;
        printf( " = %d\n", ans ) ;
        N-- ;
    }
    return 0;
}
