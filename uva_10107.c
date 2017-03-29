#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a[10005], ans, test ;
    int i, n=0, j ;
    while( scanf( "%ld", &test )==1 )
    {
        i=n-1 ;
        while( test<a[i] && i>=0 )
        {
            a[i+1]=a[i] ;
            i-- ;
        }
        if( i<0 )
            a[n]=test ;
        else
            a[i+1]=test ;
        n++ ;
        if( n%2==0 )
        {
            j=n/2 ;
            ans=a[j]+a[j-1] ;
            ans/=2; ;
        }
        else
            ans=a[n/2] ;
        printf( "%ld\n", ans ) ;
    }
    return 0;
}
