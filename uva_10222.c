#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int row1[] = { 113, 119, 101, 114, 116, 121, 117, 105, 111, 112, 91, 93 } ;
    int row2[] = { 97, 115, 100, 102, 103, 104, 106, 107, 108, 59, 39 } ;
    int row3[] = { 122, 120, 99, 118, 98, 110, 109, 44, 46, 47 } ;
    char str[1000], c ;
    int i, j, next, test ;
    gets(str) ;
    for( i = 0 ; str[i]!=NULL ; i++ )
    {
        next = 0 ;
        test = (int) str[i] ;
        for( j = 0 ; j<12 ; j++ )
            if( test==row1[j] )
            {
                c = (char) row1[j-2] ;
                printf( "%c", c ) ;
                next = 1 ;
                break ;
            }
        if( next==1 )
            continue ;
        for( j = 0 ; j<11 ; j++ )
            if( test==row2[j] )
            {
                c = (char) row2[j-2] ;
                printf( "%c", c ) ;
                next = 1 ;
                break ;
            }
        if( next==1 )
            continue ;
        for( j = 0 ; j<10 ; j++ )
            if( test==row3[j] )
            {
                c = (char) row3[j-2] ;
                printf( "%c", c ) ;
                next = 1 ;
                break ;
            }
        if( next==1 )
            continue ;
        printf( "%c", str[i] ) ;
    }
    printf( "\n" ) ;
    return 0;
}
