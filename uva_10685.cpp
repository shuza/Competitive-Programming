#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <stdio.h>

using namespace std;

int par[5002];

int getParent(int a)
{
    if(a == par[a])
        return a;
    return par[a] = getParent(par[a]);
}

int main()
{
    int C, R;
    //freopen("in.txt", "r", stdin);
    while(cin >> C >> R)
    {
        if(C == 0 && R == 0)
            break;
        map<string, int>encode;
        int sum[5002];
        for(int i = 1; i <= C; i++)
        {
            string s;
            cin >> s;
            encode[s] = i;
            par[i] = i;
            sum[i] = 1;
        }
        for(int i = 0; i < R; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int a, b;
            a = encode[s1];
            b = encode[s2];
            a = getParent(a);
            b = getParent(b);
            if(a != b)
            {
                par[b] = a;
                sum[a] += sum[b];
            }
        }
        int ans = 1;
        for(int i = 1; i <= C; i++)
            if(sum[i] > ans)
                ans = sum[i];
        cout << ans << endl;
    }
    return 0;
}
