#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};

int par[201];

int getParent(int a)
{
    if(a == par[a])
        return a;
    return par[a] = getParent(par[a]);
}

int main()
{
    int N, R, i, cost, cas = 1;
    string s1, s2;
    //freopen("in.txt", "r", stdin);
    while(cin >> N >> R)
    {
        if(N == 0 && R == 0)
            break;
        for(i = 1; i <= N; i++)
            par[i] = i;
        int top = 1;
        map<string, int>encode;
        vector<edge> G;
        for(i = 0; i < R; i++)
        {
            cin >> s1 >> s2 >> cost;
            if(!encode[s1])
                encode[s1] = top++;
            if(!encode[s2])
                encode[s2] = top++;
            edge test;
            test.u = encode[s1];
            test.v = encode[s2];
            test.w = cost;
            G.push_back(test);
        }
        int src, des;
        cin >> s1 >> s2;
        src = encode[s1];
        des = encode[s2];
        sort(G.begin(), G.end());
        int ans = 1000000;
        for(i = 0; i <G.size(); i++)
        {
            int a, b;
            a = getParent(G[i].u);
            b = getParent(G[i].v);
            if(a != b)
            {
                par[a] = b;
                if(ans > G[i].w)
                    ans = G[i].w;
            }
            if(getParent(src) == getParent(des))
                break;
        }
        cout << "Scenario #" << cas++ << endl;
        cout << ans << " tons" << endl << endl;
    }
    return 0;
}
