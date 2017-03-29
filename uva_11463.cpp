#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

#define INF (1<<30)
#define MAXNODE 105

struct node{
    int u, dis;
    node(int a, int b){
        u = a;
        dis = b;
    }
    bool operator < (const node& p) const{
        return dis > p.dis;
    }
};

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        vector<int> g[MAXNODE];
        while(r--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int src, des;
        cin >> src >> des;
        int goCost[MAXNODE];
        memset(goCost, 63, sizeof(goCost));
        priority_queue<node> q;
        goCost[src] = 0;
        q.push(node(src, 0));
        while(!q.empty()){
            node top = q.top(); q.pop();
            int u = top.u;
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(goCost[u] + 1 < goCost[v]){
                    goCost[v] = goCost[u] + 1;
                    q.push(node(v, goCost[v]));
                }
            }
        }
        int backCost[MAXNODE];
        memset(backCost, 63, sizeof(backCost));
        backCost[des] = 0;
        q.push(node(des, 0));
        while(!q.empty()){
            node top = q.top(); q.pop();
            int u = top.u;
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(backCost[u] + 1 < backCost[v]){
                    backCost[v] = backCost[u] + 1;
                    q.push(node(v, backCost[v]));
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
            if(goCost[i] + backCost[i] > ans)
                ans = goCost[i] + backCost[i];
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
