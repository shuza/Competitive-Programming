#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int L, H, i, count, max, num ;
    while( scanf( "%lu %lu", &L, &H )==2 )
    {
        printf( "%lu %lu ", L, H ) ;
        if( L>H )
        {
            num = L ;
            L = H ;
            H = num ;
        }
        max = 0 ;
        for( i = L ; i<=H ; i++ )
        {
            count = 1 ;
            num = i ;
            while( num!=1 )
            {
                if( num%2==0 )
                    num /= 2 ;
                else
                    num = 3 * num + 1 ;
                count++ ;
            }
            if( count>max )
                max = count ;
        }
        printf( "%u\n", max ) ;
    }
    return 0;
}
