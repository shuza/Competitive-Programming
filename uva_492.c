#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, test ;
    int k=0 ;
    while( scanf( "%c", &c)==1 )
    {
        if( c>='A' && c<='z')
        {
            if( k==0 )
            {
                if( c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u' )
                {
                    k=1 ;
                    printf( "%c", c ) ;
                }
                else
                {
                    test = c ;
                    k = 2;
                }
            }
            else
                printf( "%c", c ) ;
        }
        else if( k==1 )
        {
            printf( "ay%c", c ) ;
            k=0 ;
        }
        else if( k==2 )
        {
            printf( "%cay%c", test, c ) ;
            k=0 ;
        }
        else
        {
            printf( "%c", c ) ;
            k=0 ;
        }
    }
    return 0;
}
