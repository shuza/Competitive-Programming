#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    int r;
    while(a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    int N, i, j, ans;
    while(cin >> N)
    {
        if(N == 0)
            break;
        ans = 0;
        for(i = 1; i < N; i++)
            for(j = i+1; j <= N; j++)
                ans += GCD(i, j);
        cout << ans << endl;
    }
    return 0;
}
