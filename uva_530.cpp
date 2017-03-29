#include <iostream>

using namespace std;

long gcd ( long a, long b )
{
    if( a%b==0 )
        return b ;
    else
        return gcd( b, a%b ) ;
}
void Divbygcd( long &a, long &b )
{
    long g=gcd( a, b ) ;
    a/=g ;
    b/=g ;
}
long C( int n, int k )
{
    long numerator=1, denominator=1, toMul, toDiv, i ;
    if( k>n/2 )
        k=n-k ;
    for( i=k ; i ; i-- )
    {
         toMul=n-k+i ;
         toDiv=i ;
         Divbygcd( toMul, toDiv ) ;
         Divbygcd( numerator, denominator ) ;
         Divbygcd( toMul, toDiv ) ;
         numerator*=toMul ;
         denominator*=toDiv ;
    }
    return numerator/denominator ;
}

int main()
{
    long int a, b, ans ;
    cin >> a >> b ;
    while( a!=0 || b!=0 )
    {
        ans=C( a, b ) ;
        cout << ans << endl ;
        cin >> a >> b ;
    }
    return 0;
}
