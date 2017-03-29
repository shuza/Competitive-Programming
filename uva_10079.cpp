#include <iostream>

using namespace std;

int main()
{
    long N;
    while(cin >> N)
    {
        if(N < 0)
            break;
        unsigned long long ans = (unsigned long long) N * (N + 1) / 2;
        cout << ans+1 << endl;
    }
    return 0;
}
