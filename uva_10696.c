#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int input, ans ;
    while( scanf( "%ld", &input )==1 )
    {
        if( input==0 )
            break ;
        if( input>100 )
            ans=input-10 ;
        else
            ans=91 ;
        printf( "f91(%ld) = %ld\n", input, ans ) ;
    }
    return 0;
}
