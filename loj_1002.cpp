#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

#define MAXNODE 503

using namespace std;

struct data{
    int u, v, w;
    bool operator < (const data& p) const{
        return w < p.w;
    }
};

int p[MAXNODE], cost[MAXNODE][MAXNODE], ans[MAXNODE];
vector<int> v[MAXNODE];

void setParent(int n){
    for(int i = 0; i <= n; i++){
        p[i] = i;
        ans[i] = -1;
    }
}

int getParent(int a){
    if(p[a] == a)
        return a;
    return p[a] = getParent(p[a]);
}

void fun(int u, int w){
    if(ans[u] != -1)
        return;
    ans[u] = w;
    for(int i = 0; i < v[u].size(); i++){
        int b = v[u][i];
        if(cost[u][b] > w)
            fun(b, cost[u][b]);
        else
            fun(b, w);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    scanf("%d", &t);
    while(t--){
        vector<data> edge;
        int n, m;
        scanf("%d %d", &n, &m);
        while(m--){
            data test;
            scanf("%d %d %d", &test.u, &test.v, &test.w);
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        setParent(n);
        int taken = 0;
        for(int i = 0; i < edge.size(); i++){
            int a, b;
            a = getParent(edge[i].u);
            b = getParent(edge[i].v);
            if(a != b){
                p[a] = b;
                v[edge[i].u].push_back(edge[i].v);
                v[edge[i].v].push_back(edge[i].u);
                cost[edge[i].u][edge[i].v] = cost[edge[i].v][edge[i].u] = edge[i].w;
                taken++;
            }
            if(taken == n - 1)
                break;
        }
        scanf("%d", &m);
        fun(m, 0);
        printf("Case %d:\n", cas++);
        for(int i = 0; i < n; i++)
            if(ans[i] != -1)
                printf("%d\n", ans[i]);
            else
                puts("Impossible");
        for(int i = 0; i <= n; i++)
            v[i].clear();
        memset(cost, 0, sizeof(cost));
    }
    return 0;
}
