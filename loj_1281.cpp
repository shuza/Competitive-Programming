#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAXCITY 10005

struct node{
    int u, w, t;
    node(int a, int b, int c){
        u = a; w = b; t = c;
    }
    bool operator < (const node& p) const {
        return w > p.w;
    }
};

vector<int> gOld[MAXCITY], gNew[MAXCITY], costOld[MAXCITY], costNew[MAXCITY];
long dis[MAXCITY][12];

long dijkstra(int src, int n, int d){
    memset(dis, 63, sizeof(dis));
    priority_queue<node> q;
    q.push(node(src, 0, 0));
    dis[src][0] = 0;
    while(!q.empty()){
        node top = q.top(); q.pop();
        int u = top.u;
        if(u == n){
            long ans = 1<<30;
            for(int i = 0; i < 12; i++)
                if(dis[u][i])
                    ans = min(ans, dis[u][i]);
            return ans;
        }
        for(int i = 0; i < gOld[u].size(); i++){
            int v = gOld[u][i];
            if(dis[u][top.t] + costOld[u][i] < dis[v][top.t]){
                dis[v][top.t] = dis[u][top.t] + costOld[u][i];
                q.push(node(v, dis[v][top.t], top.t));
            }
        }
        for(int i = 0; i < gNew[u].size() && top.t < d; i++){
            int v = gNew[u][i];
            if(dis[u][top.t] + costNew[u][i] < dis[v][top.t+1]){
                dis[v][top.t+1] = dis[u][top.t] + costNew[u][i];
                q.push(node(v, dis[v][top.t+1], top.t+1));
            }
        }
    }
    return -1;
}

void reset(){
    for(int i  = 0; i < MAXCITY; i++){
        costOld[i].clear();
        costNew[i].clear();
        gOld[i].clear();
        gNew[i].clear();
    }
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        reset();
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            gOld[u].push_back(v);
            costOld[u].push_back(w);
        }
        while(k--){
            int u, v, w;
            cin >> u >> v >> w;
            gNew[u].push_back(v);
            costNew[u].push_back(w);
        }
        long ans = dijkstra(0, n-1, d);
        cout << "Case " << cas++ << ": ";
        if(ans != -1)
            cout << ans << endl;
        else
            puts("Impossible");
    }
    return 0;
}