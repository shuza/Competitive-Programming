#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int a, b, ans, test ;
    short int binary[33], i, a1, b1 ;
    while( scanf( "%lu %lu", &a, &b )!=EOF )
    {
        i=0 ;
        while( a!=0 || b!=0 )
        {
            a1=0 ;
            b1=0 ;
            if( a!=0 )
                a1=a%2 ;
            if( b!=0 )
                b1=b%2 ;
            a/=2 ;
            b/=2 ;
            test=a1+b1 ;
            if( test==2 )
                binary[i]=0 ;
            else if( test==1 )
                binary[i]=1 ;
            else
                binary[i]=0 ;
            i++ ;
        }
        i-- ;
        ans=0 ;
        while( i>=0 )
        {
            ans+=binary[i]*pow( 2,i ) ;
            i-- ;
        }
        printf( "%lu\n", ans ) ;
    }
    return 0;
}
