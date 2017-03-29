#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T, n, median, i, a[500], ans ;
    cin >> T ;
    while( T>0 )
    {
        cin >> n ;
        for( i = 0 ; i<n ; i++ )
            cin >> a[i] ;
        sort( a, a+n ) ;
        if( n%2==0 )
        {
            median = n/2 ;
            median = ( a[median] + a[median-1] ) /2 ;
        }
        else
            median = a[n/2] ;
        ans = 0 ;
        for( i = 0 ; i<n ; i++ )
            ans += abs( median - a[i] ) ;
        cout << ans << endl ;
        T-- ;
    }
    return 0;
}
