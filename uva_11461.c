#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a, b, test ;
    int i, ans ;
    while( scanf( "%ld %ld", &a, &b)==2 )
    {
        if( a==0 && b==0 )
            break ;
        ans=0 ;
        test=0 ;
        for( i=1 ; test<=b ; i++ )
        {
            test=i*i ;
            if( test>=a && test<=b )
                ans++ ;
        }
        printf( "%d\n", ans ) ;
    }
    return 0;
}
