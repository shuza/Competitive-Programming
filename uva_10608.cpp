#include <iostream>
#include <stdio.h>

using namespace std;

int par[30002], sum[30002];

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        sum[i] = 1;
    }
}

int getParent(int a)
{
    if(a == par[a])
        return a;
    return par[a] = getParent(par[a]);
}

int main()
{
    int cas,N, i;
    long M;
    //freopen("in.txt", "r", stdin);
    cin >> cas;
    while(cas--)
    {
        cin >> N >> M;
        init(N);
        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            a = getParent(a);
            b = getParent(b);
            if(a != b)
            {
                par[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = sum[1];
        for(int i = 2; i <= N; i++)
            if(sum[i] > ans)
                ans = sum[i];
        cout << ans << endl;
    }
    return 0;
}
