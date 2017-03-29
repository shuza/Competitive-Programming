#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#define MAXNODE 12
using namespace std;

struct node{
    int u, w;
    node(int a, int b)  {u = a; w = b;}
    bool operator < (const node& p) const{
        return w > p.w;
    }
};

vector<int> g[MAXNODE], cost[MAXNODE];
int p[MAXNODE];

int dij(int src, int des){
    int dis[MAXNODE];
    memset(dis, 63, sizeof(dis));
    dis[src] = 0;
    priority_queue<node> q;
    q.push(node(src, 0));
    while(!q.empty()){
        node top = q.top(); q.pop();
        int u = top.u;
        if(u == des)
            return dis[u];
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[u] + cost[u][i] < dis[v]){
                dis[v] = dis[u] + cost[u][i];
                q.push(node(v, dis[v]));
                p[v] = u;
            }
        }
    }
    return 0;
}

void path(int s){
    if(p[s] == s)
        return;
    path(p[s]);
    cout << " " << s;
}

void reset(){
    for(int i = 0; i < MAXNODE; i++){
        g[i].clear();
        cost[i].clear();
        p[i] = 0;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int n, cas = 1;
    while(cin >> n){
        if(!n)
            break;
        reset();
        for(int i = 1; i <= n; i++){
            int m;
            cin >> m;
            while(m--){
                int u, w;
                cin >> u >> w;
                g[i].push_back(u);
                cost[i].push_back(w);
            }
        }
        int s, d;
        cin >> s >> d;
        int ans = dij(s, d);
        cout << "Case " << cas++ << ": Path =";
        path(d);
        cout << "; " << ans << " second delay" << endl;
    }
    return 0;
}
