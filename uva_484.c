#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[32768], ans[32768], test, i ,j ;
    freopen( "in.txt", "r", stdin ) ;
    while( scanf( "%d", &test )==1 )
    {
        j=0 ;
        while( j<i )
        {
            if( a[j]==test )
            {
                ans[j]+=1 ;
                break ;
            }
            j++ ;
        }
        if( a[j]!=test )
        {
            a[i]=test ;
            ans[i]=1 ;
            i++ ;
        }
    }
    for( j=0 ; j<i ; j++ )
        printf( "%d %d\n", a[j], ans[j] ) ;
    return 0;
}
