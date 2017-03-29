#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define LONGMAX 2147483647

using namespace std;

struct data
{
    int u, v, cost;
    bool operator <(const data& p) const
    {
        return cost < p.cost;
    }
};

int parent[102];
vector<data> edge;

void setParent(int n)
{
    for(int i = 0; i <= n; i++)
        parent[i] = i;
}

int getParent(int a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = getParent(parent[a]);
}

long MST(int r, int v)
{
    long total = 0, i, taken = 0, a, b;
    setParent(v);
    for(i = 0; i < edge.size(); i++)
    {
        if(i == r)
            continue;
        a = getParent(edge[i].u);
        b = getParent(edge[i].v);
        if(a != b)
        {
            total += edge[i].cost;
            parent[a] = b;
            taken++;
        }
    }
    if(taken < v - 1)
        return -1;
    return total;
}

int main()
{
    int t, cas = 1, v, e, i, a, b, test;
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        edge.clear();
        for(i = 0; i < e; i++)
        {
            data test;
            cin >> test.u >> test.v >> test.cost;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        setParent(v);
        test = 0;
        int mark[202] = {0};
        for(i = 0; i < edge.size(); i++)
        {
            a = getParent(edge[i].u);
            b = getParent(edge[i].v);
            if(a != b)
            {
                test++;
                parent[a] = b;
                mark[i] = 1;
            }
        }
        if(test < v - 1)
        {
            cout << "Case #" << cas++ << " : No way" << endl;
            continue;
        }
        long ans, testMst;
        ans = LONGMAX;
        for(i = 0; i < e; i++)
            if(mark[i])
            {
                testMst = MST(i, v);
                if(testMst < ans && testMst != -1)
                    ans = testMst;
            }
        if(ans != LONGMAX)
            cout << "Case #" << cas++ << " : " << ans << endl;
        else
            cout << "Case #" << cas++ << " : No second way" << endl;
    }
    return 0;
}
