#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define EPS 0.000000001
#define MAXNODE 1005

using namespace std;

struct data
{
    int u, v;
    double cost;
    bool operator <(const data& p) const
    {
        return cost < p.cost;
    }
};

int parent[MAXNODE];

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
    int testCase, cas = 1;
 //   freopen("in.txt", "r", stdin);
    cin >> testCase;
    while(testCase--)
    {
        int n, i, j;
        double r;
        cin >> n >> r;
        int x[MAXNODE], y[MAXNODE];
        for(i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        vector<data> edge;
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++)
            {
                double dis = (x[i] - x[j]) * (x[i] - x[j]);
                dis += (y[i] - y[j]) * (y[i] - y[j]);
                dis = sqrt(dis);
                data test;
                test.u = i + 1;
                test.v = j + 1;
                test.cost = dis;
                edge.push_back(test);
            }
        sort(edge.begin(), edge.end());
        int taken = 0, state = 1;
        double road = 0, rail = 0;
        setParent(n);
        for(i = 0; i < edge.size(); i++)
        {
            int a, b;
            a = getParent(edge[i].u);
            b = getParent(edge[i].v);
            if(a != b)
            {
                if(edge[i].cost + EPS < (double) r)
                    road += edge[i].cost;
                else
                {
                    rail += edge[i].cost;
                    state++;
                }
                parent[a] = b;
                taken++;
                if(taken == n - 1)
                    break;
            }
        }
        cout << "Case #" << cas++ << ": " << state << " " << (int) (road + 0.5) << " " << (int) (rail + 0.5) << endl;
    }
    return 0;
}
