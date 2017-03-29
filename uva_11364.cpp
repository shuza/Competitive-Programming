#include <iostream>

using namespace std;

int main()
{
    int T, n, i, test, a[100], max, min ;
    cin >> T ;
    while( T>0 )
    {
        cin >> n ;
        min=100 ;
        max=0 ;
        for( i=0 ; i<n ; i++ )
        {
            cin >> test ;
            if( test<min )
                min=test ;
            if( test>max )
                max=test ;
        }
        max=2*( max-min ) ;
        cout << max << endl ;
        T-- ;
    }
    return 0;
}
