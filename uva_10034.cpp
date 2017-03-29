#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#define EPS 0.0000000009
#define MAXNODE 111

using namespace std;

struct data
{
    int u, v;
    double cost;
    bool operator <(const data& p) const
    {
        return cost + EPS < p.cost;
    }
};

int parent[MAXNODE];
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

int main()
{
    int t, n, i, j;
    double x[MAXNODE], y[MAXNODE];
//    freopen("in.txt", "r", stdin);
    bool line = false;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
            {
                double dis = (x[i] - x[j]) * (x[i] - x[j]);
                dis += (y[i] - y[j]) * (y[i] - y[j]);
                dis = (double) sqrt(dis);
                data test;
                test.u = i + 1;
                test.v = j + 1;
                test.cost = dis;
                edge.push_back(test);
            }
        double ans = 0;
        int taken = 0;
        setParent(n);
        sort(edge.begin(), edge.end());
        for(i = 0; i < edge.size(); i++)
        {
            int a, b;
            a = getParent(edge[i].u);
            b = getParent(edge[i].v);
            if(a != b)
            {
                parent[a] = b;
                ans += edge[i].cost;
                taken++;
                if(taken == n - 1)
                    break;
            }
        }
        if(line)
            cout << endl;
        line = true;
        printf("%.2lf\n", ans);
        edge.clear();
    }
    return 0;
}
