#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c ;
    int i, n, line = 0 ;
    while( scanf( "%c", &c )!=EOF )
    {
        if( c=='!' )
        {
            printf( "\n" ) ;
            continue ;
        }else if( c=='\n' )
        {
            if( line==0 )
            {
                printf( "\n" ) ;
                line = 1 ;
                continue ;
            }
            else
            {
                while( c=='\n' )
                    scanf( "%c", &c ) ;
                printf( "\n" ) ;
                line = 0 ;
            }
        }
        n = 0 ;
        while( c>='0' && c<='9' )
        {
            i = (int) c -48 ;
            n += i ;
            scanf( "%c", &c ) ;
        }
        line = 0 ;
        for( i = 0 ; i<n ; i++ )
            if( c=='b' )
                printf( " " ) ;
            else
                printf( "%c", c ) ;
    }

    return 0;
}
