#include <iostream>

using namespace std;

int main()
{
    long N;
    while(cin >> N)
    {
        long long ans = 0;
        for(long i = 1; i <= N; i++)
            ans += i*i*i;
        cout << ans << endl;
    }
    return 0;
}
