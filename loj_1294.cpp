#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T, cas = 1;
    long long n, m, ans, x, odd;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        if(n/m == 2)
            ans = ((n*(n+1))/2) - 2*((m*(m+1))/2);
        else
        {
            x = (n/m) - 1;
            odd = (x/2) + 1;
            x -= odd;
            ans = (x*(x+1)) - x + (2*x+1) - (x*(x+1));
            ans *= m * m;
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
