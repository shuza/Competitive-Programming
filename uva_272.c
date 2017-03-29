#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c ;
    int a=0 ;
    while( scanf( "%c", &c)!=EOF )
    {
        if( c=='"' )
        {
            if( a==0 )
            {
                printf( "``" ) ;
                a=1 ;
            }
            else
            {
                printf( "''" ) ;
                a=0 ;
            }
        }
        else
            printf( "%c", c ) ;
    }
    return 0;
}
