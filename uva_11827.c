#include <stdio.h>
#include <stdlib.h>

int GCD( int a, int b )
{
    int r ;
    while( a%b!=0 )
    {
        r=a%b ;
        a=b ;
        b=r ;
    }
    return b ;
}

int main()
{
    char in[100000] ;
    int N, i, j, test, n, a[100], ans ;
    scanf( "%d\n", &N ) ;
    while( N>0 )
    {
        gets( in ) ;
        i=0 ;
        j=0 ;
        test=0 ;
        n=0 ;
        while( in[i]!='\0' )
        {
            n=( int ) in[i]-48 ;
            if( n>=0 && n<=9 )
                test=test*10+n ;
            else if( in[i]==' ' && test!=0 )
            {
                a[j]=test ;
                test=0 ;
                j++ ;
            }
            i++ ;
        }
        if( test!=0 )
            a[j++]=test ;
        n=j ;
        ans=0 ;
        for( i=0 ; i<n ; i++ )
            for( j=i+1 ; j<n ; j++ )
            {
                test=GCD( a[i], a[j] ) ;
                if( test>ans )
                    ans=test ;
            }
        printf( "%d\n", ans ) ;
        N-- ;
    }
    return 0;
}
