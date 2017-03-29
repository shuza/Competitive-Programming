#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[1000], frq[1000], i, j, count, test, line = 0 ;
    char str[1001] ;
    freopen( "in.txt", "r", stdin ) ;
    freopen( "out.txt", "w", stdout ) ;
    while( gets(str) )
    {
        count = 0 ;
        i = 0 ;
        while( str[i]!=NULL )
        {
            test = (int) str[i] ;
            if( test<32 || test>127 )
            {
                i++ ;
                continue ;
            }
                for( j = 0 ; j<count ; j++ )
                    if( test==arr[j] )
                    {
                        frq[j] += 1 ;
                        break ;
                    }
                if( j==count )
                {
                    arr[count] = test ;
                    frq[count] = 1 ;
                    count++ ;
                }
            i++ ;
        }
        for( i = 0 ; i<count ; i++ )
            for( j = 1; j<count ; j++ )
                if( frq[j-1]>frq[j] )
                {
                    test = frq[j-1] ;
                    frq[j-1] = frq[j] ;
                    frq[j] = test ;
                    test = arr[j-1] ;
                    arr[j-1] = arr[j] ;
                    arr[j] =test ;
                }
                else if( frq[j-1]==frq[j] && arr[j-1]<arr[j] )
                {
                    test = arr[j-1] ;
                    arr[j-1] = arr[j] ;
                    arr[j] = test ;
                }
        if( line!=0 )
            printf( "\n" ) ;
        for( i = 0 ; i<count ; i++ )
            printf( "%d %d\n", arr[i], frq[i] ) ;
        line = 1 ;
    }
    return 0;
}
