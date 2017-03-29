#include <stdio.h>
#include <stdlib.h>

int coin[]={ 1, 5, 10, 25, 50 } ;

long long int change( int n )
{
    long long int nway[7490]={0} ;
    int i, j, c ;
    nway[0]=1 ;
    for( i=0 ; i<5 ; i++ )
    {
        c=coin[i] ;
        for( j=c ; j<=n ; j++ )
            nway[j]+=nway[j-c] ;
    }
    return nway[n] ;
}

int main()
{
    int n ;
    long long int ans ;
    while( scanf( "%d", &n )==1 )
    {
        if( n==0 )
            ans=0 ;
        else
            ans=change( n ) ;
        printf( "%lld\n", ans ) ;
    }
    return 0;
}
