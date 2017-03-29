#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int l, test ;
    int a, b, c, d, ans, i ;
    while( scanf( "%d %d %d %d %ld", &a, &b, &c, &d, &l )==5 )
    {
        if( a==0 && b==0 && c==0 && d==0 && l==0 )
            break ;
        ans=0 ;
        for( i=0 ; i<=l ; i++ )
        {
            test=a*i*i + b*i + c ;
            if( test%d==0 )
                ans++ ;
        }
        printf( "%d\n", ans) ;
    }
    return 0;
}
