#include <iostream>

using namespace std;

int main()
{
    int T, a, b, n, ans ;
    cin >> T ;
    while( T>0 )
    {
        cin >> a >> b >> n ;
        a+=b ;
        ans=0 ;
        while( a>=n )
        {
            ans+=a/n ;
            a=( a/n )+( a%n ) ;
        }
        cout << ans << endl ;
        T-- ;
    }
    return 0;
}
