#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

long long dp[55];

long long cal(int a)
{
    if(a == 0)
        return 0;
    if(dp[a] != 0)
        return dp[a];
    dp[a] = cal(a - 1) + cal(a - 2);
    return dp[a];
}

int main()
{
    int N;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    dp[1] = 1;
    dp[2] = 2;
    cal(51);
    while(cin >> N)
    {
        if(N == 0)
            break;
        cout << dp[N] << endl;
    }
    return 0;
}
