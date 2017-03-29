#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#define MAXJ 105
vector<int>g[MAXJ], cost[MAXJ];

struct data{
    int u, w;
    data(int a,int c){
        u = a;  w = c;
    }
    bool operator < (const data& p) const{
        return w > p.w;
    }
};

long dijkstra(int src, int des){
    long dis[MAXJ];
    memset(dis, 63, sizeof(dis));
    priority_queue<data> q;
    dis[src] = 0;
    q.push(data(src, 0));
    while(!q.empty()){
        data top = q.top();
        q.pop();
        int u = top.u;
        if(u == des)
            return dis[des];
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[u] + cost[u][i] < dis[v]){
                dis[v] = dis[u] + cost[u][i];
                q.push(data(v, dis[v]));
            }
        }
    }
    return 0;
}

void reset(){
    for(int i = 0; i < MAXJ; i++){
        g[i].clear();
        cost[i].clear();
    }
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        reset();
        int n, m;
        cin >> n >> m;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        long ans = dijkstra(1, n);
        cout << "Case " << cas++ << ": ";
        if(ans)
            cout << ans << endl;
        else
            puts("Impossible");
    }
    return 0;
}
