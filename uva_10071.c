#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v, t, ans ;
    while( scanf( "%d %d", &v, &t )==2 )
    {
        ans=v*2*t ;
        printf( "%d\n", ans ) ;
    }
    return 0;
}
