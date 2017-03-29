#include <stdio.h>
#include <stdlib.h>

char num( char c )
{
    if( c=='A' || c=='B' || c=='C' )
        return '2' ;
    if( c=='D' || c=='E' || c=='F' )
        return '3' ;
    if( c=='G' || c=='H' || c=='I' )
        return '4' ;
    if( c=='J' || c=='K' || c=='L' )
        return '5' ;
    if( c=='M' || c=='N' || c=='O' )
        return '6' ;
    if( c=='P' || c=='Q' || c=='R' || c=='S' )
        return '7' ;
    if( c=='T' || c=='U' || c=='V' )
        return '8' ;
    return '9' ;
}

int main()
{
    char input[31], c, ans[31] ;
    int i ;
    while( scanf( "%s", input )!=EOF )
    {
        i=0 ;
        while( input[i]!='\n' && input[i]!='\0' )
        {
            if( input[i]>='A' && input[i]<='Z' )
                ans[i]=num( input[i] ) ;
            else
                ans[i]=input[i] ;
            i++ ;
        }
        ans[i]='\0' ;
        printf( "%s\n", ans ) ;
    }
    return 0;
}
