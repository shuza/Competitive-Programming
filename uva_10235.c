#include <stdio.h>
#include <stdlib.h>

int prime( long int a )
{
    long int i, sq ;
    sq=sqrt( a ) ;
    for( i=2 ; i<=sq ; i++ )
        if( a%i==0 )
            return 2 ;
    return 1 ;
}

int main()
{
    long int input, a, i, b ;
    while( scanf( "%ld", &input )==1 )
    {
        i=prime( input ) ;
        if( i==2 )
            printf( "%ld is not prime.\n", input ) ;
        else
        {
            a=input ;
            b=0 ;
            while( a!=0 )
            {
                b=b*10+a%10 ;
                a/=10 ;
            }
            i=prime( b ) ;
            if( i==1 && b!=input )
                printf( "%ld is emirp.\n", input ) ;
            else
                printf( "%ld is prime.\n", input ) ;
        }
    }
    return 0;
}
