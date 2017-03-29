#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n ;
    char ans[10000], gase[10000] ;
    cin >> n ;
    while( n!=-1 )
    {
        cin >> ans >> gase ;
        int error=0, solve=0, i, j, test, l ;
        for( i=0 ; gase[i]!='\0' ; i++ )
        {
            test=0 ;
            for( j=0 ; j<i ; j++ )
                if( gase[i]==gase[j] )
                {
                    test=1 ;
                    break ;
                }
            if( test==1 )
                continue ;
            l=strlen( ans ) ;
            test=0 ;
            for( j=0 ; ans[j]!='\0' ; j++ )
            {
                if( gase[i]==ans[j] )
                {
                    solve++ ;
                    test=1 ;
                }
            }
            if( test==0 )
                error++ ;
            if( l==solve )
                break ;
        }
        cout << "Round " << n << endl ;
        if( error>=7 )
            cout << "You lose." << endl ;
        else if( solve==l )
            cout << "You win." << endl ;
        else
            cout << "You chickened out." << endl ;
        cin >> n ;
    }
    return 0;
}
