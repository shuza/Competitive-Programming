#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int prime[] = { 2, 3, 5, 7, 13, 17, 19, 31 } ;
    int notperfect[] = { 11, 23, 29 } ;
    int n ;
    while( cin >> n )
    {
        if( !n )
            break ;
        if( notperfect[0]==n || notperfect[1]==n || notperfect[2]==n )
        {
            cout << "Given number is prime. But, NO perfect number is available." << endl ;
            continue ;
        }
        bool perfect = false ;
        for( int i = 0 ; i<8 ; i++ )
            if( prime[i]== n )
            {
                perfect = true ;
                break ;
            }
        if( perfect )
        {
            long long int ans ;
            ans = pow( 2, n-1 ) ;
            ans *= pow( 2, n ) - 1 ;
            cout << "Perfect: " << ans << "!" << endl ;
        }
        else
            cout << "Given number is NOT prime! NO perfect number is available." << endl ;
    }
    return 0;
}
