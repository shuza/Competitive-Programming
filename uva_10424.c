#include <stdio.h>
#include <stdlib.h>

int fun( char c[27] )
{
    int test, i=0, ans=0 ;
    while( c[i]!='\0' )
    {
        if( c[i]>='A' && c[i]<='z' )
        {
            test=(int) c[i]-64 ;
            ans+=test%32 ;
        }
        i++ ;
    }
    return ans ;
}
int num( int a )
{
    int test=0 ;
    while( a!=0 )
    {
        test+=a%10 ;
        a/=10 ;
    }
    return test ;
}

int main()
{
    char a[27], b[27] ;
    int a1, b1 ;
    double ans ;
    while( gets( a) )
    {
        gets( b ) ;
        a1=fun( a ) ;
        b1=fun( b ) ;
        while( a1>9 )
            a1=num( a1 ) ;
        while( b1>9 )
            b1=num( b1 ) ;
        if( a1>b1 )
            ans=(double) b1/a1 ;
        else
            ans=( double) a1/b1 ;
        ans*=100 ;
        printf( "%.2lf %c\n", ans, 37 ) ;
    }
    return 0;
}
