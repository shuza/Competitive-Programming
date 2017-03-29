#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

struct data
{
    int u, v, w;
    bool operator <(const data& p) const
    {
        return w < p.w;
    }
};

long parent[1000005];

long getparent(long a)
{
    if(parent[a] == a)
        return a;
    return parent[a] = getparent(parent[a]);
}

int main()
{
    long N;
    bool line = false;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    while(cin >> N)
    {
        if(line)
            cout << endl;
        else
            line = true;
        long long i, M, sum = 0;
        data test;
        vector<data> edge;
        for(i = 1; i < N; i++)
        {
            cin >> test.u >> test.v >> test.w;
            sum += test.w;
            parent[i] = i;
        }
        parent[i] = i;
        cout << sum << endl;
        cin >> M;
        for(i = 0; i < M; i++)
        {
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        cin >> M;
        while(M--)
        {
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        sum = 0;
        long taken = 0;
        for(i = 0; i < edge.size(); i++)
        {
            long a, b;
            a = getparent(edge[i].u);
            b = getparent(edge[i].v);
            if(a != b)
            {
                parent[b] = a;
                sum += edge[i].w;
                taken++;
                if(taken == N - 1)
                    break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
