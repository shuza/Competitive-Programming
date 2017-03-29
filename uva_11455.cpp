#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N ;
    cin >> N ;
    while( N-- )
    {
        int a[4] ;
        cin >> a[0] >> a[1] >> a[2] >> a[3] ;
        sort( a, a+4 ) ;
        if( a[0]==a[1] && a[1]==a[2] && a[2]==a[3] )
            cout << "square" << endl ;
        else if( a[0]==a[1] && a[2]==a[3] )
            cout << "rectangle" << endl ;
        else if( a[0]+a[1]+a[2]>=a[3] )
            cout << "quadrangle" << endl ;
        else
            cout << "banana" << endl ;
    }
    return 0;
}
