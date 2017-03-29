#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, ans, l ;
    char input[6] ;
    scanf( "%d", &count ) ;
    while( count>0 )
    {
        scanf( "%s", input ) ;
        l=strlen( input ) ;
        if( l==3 )
        {
            if( (input[0]=='t' && input[1]=='w') || (input[1]=='w' && input[2]=='o') || (input[2]=='o' && input[0]=='t') )
                printf( "2\n" ) ;
            else
                printf( "1\n" ) ;
        }
        else
            printf( "3\n" ) ;
        count-- ;
    }
    return 0;
}
