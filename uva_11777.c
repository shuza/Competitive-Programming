#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, count=1, a[7], i, test ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6] ) ;
        test=a[4] ;
        if( a[5]<test && a[5]<a[6] )
            test=a[5] ;
        else if( a[6]<test && a[6]<a[5] )
            test=a[6] ;
        test=( a[4]+a[5]+a[6]-test )/2 ;
        test+=a[0]+a[1]+a[2]+a[3] ;
        test/=10 ;
        switch( test )
        {
            case 10:
            case 9:
                printf( "Case %d: A\n", count ) ;
                break ;
            case 8:
                printf( "Case %d: B\n", count ) ;
                break ;
            case 7:
                printf( "Case %d: C\n", count ) ;
                break ;
            case 6:
                printf( "Case %d: D\n", count ) ;
                break ;
            default:
                printf( "Case %d: F\n", count ) ;
                break ;
        }
        count++ ;
    }
    return 0;
}
