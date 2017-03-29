#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, cas = 1;
    long r[100005], ans, n, i;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        ans = -99;
        r[0] = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> r[i];
            if(r[i] - r[i-1] > ans)
                ans = r[i] - r[i-1];
        }
        long test = ans;
        for(i = 0; i <= n; i++)
        {
            if(r[i] - r[i-1] == test)
                test--;
            else if((r[i] - r[i-1] > test) || (test == 0 && i < n))
            {
                test = ++ans;
                i = 0;
            }
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
