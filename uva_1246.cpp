#include <iostream>
#include <math.h>

using namespace std;

int fun( int a )
{
    int i, ans = 0 ;
    for( i = 2 ; i<=a ; i++ )
        if( a%i==0 )
            ans++ ;
    ans++ ;
    return ans ;
}

int main()
{
    unsigned short int T ;
    int L, H, i, j, factor, test, test1, ans ;
    cin >> T ;
    while( T>0 )
    {
        cin >> L >> H ;
        factor = 0 ;
        ans= 0 ;
        for( i = L ; i<=H ; i++ )
        {
            factor = fun( i ) ;
            test = 0 ;
            test1 = sqrt( factor ) ;
            for( j = 2 ; j<=test1 ; j++ )
                if( factor%j==0 )
                {
                    test = 1 ;
                    break ;
                }
            if( test==0 && factor!=1 && ans==0 )
            {
                ans++ ;
                cout << i ;
            }
            else if( test==0 && factor!=1 )
            {
                ans++ ;
                cout << " " << i ;
            }
        }
        if( ans==0 )
            cout << "-1" ;
        cout << endl ;
        T-- ;
    }
    return 0;
}
