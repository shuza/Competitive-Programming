#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, a[20002], i, j, n, test, b ;
    scanf( "%d", &T ) ;
    while( T>0 )
    {
        scanf( "%d", &n ) ;
        for( i=0 ; i<n ; i++ )
        {
            scanf( "%d", &test ) ;
            j=i ;
            while( test<a[j] && j>=0 )
            {
                a[j+1]=a[j] ;
                j-- ;
            }
            if( j<0 )
                a[i+1]=test ;
            else
                a[j+1]=test ;
        }
        test=0 ;
        for( i=n-2 ; i>=0 ; i-=3 )
            test+=a[i] ;
        printf( "%d\n", test ) ;
        T-- ;
    }
    return 0;
}
