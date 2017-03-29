#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

#define MAXNODE 20005

vector<int> g[MAXNODE], cost[MAXNODE];

struct data{
    int u, w;
    data(int a, int b){
        u = a;  w = b;
    }
    bool operator < (const data& p) const{
        return w > p.w;
    }
};

long dijkart(int s, int t){
    long dis[MAXNODE];
    memset(dis, 63, sizeof(dis));
    priority_queue<data> q;
    dis[s] = 0;
    q.push(data(s, 0));
    while(!q.empty()){
        data top = q.top();
        q.pop();
        int u = top.u;
        if(u == t)
            return dis[t];
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
    for(int i = 0; i < MAXNODE; i++){
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
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        long ans = dijkart(s, t);
        cout << "Case #" << cas++ << ": ";
        if(ans)
            cout << ans << endl;
        else
            puts("unreachable");
    }
    return 0;
}
