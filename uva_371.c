#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int ans, test, test_1, L, H, value, i;
    while( scanf( "%ld %ld", &L, &H)==2 )
    {
        if( L==0 && H==0 )
            break;
        if( L > H )
        {
            test = L;
            L = H;
            H = test;
        }
        ans = 0;
        value = L;
        printf( "Between %ld and %ld, ", L, H );
        while( L <= H )
        {
            test = L;
            test_1 = 0;
            do
            {
                test_1++;
                if( test%2 )
                    test = 3 * test + 1;
                else
                    test /= 2;
            }while( test != 1 );
            if( test_1 > ans )
            {
                ans = test_1;
                value = L;
            }
            L++;
        }
        printf( "%ld generates the longest sequence of %ld values.\n", value, ans );
    }
    return 0;
}
