#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)

#define MAXNODE 5003

vector<int> g[MAXNODE];
int parent[MAXNODE];

void reset(){
    for(int i = 0; i < MAXNODE; i++)
        g[i].clear();
}

int bfs(int u, int destination){
    int dis[MAXNODE];
    memset(parent, -1, sizeof(parent));
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();  q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
                parent[v] = u;
                if(v == destination)
                    return dis[v];
            }
        }
    }
    return -1;
}


int main()
{
    READ;
    int n;
    while(cin >> n){
        if(!n)  break;
        reset();
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int q;
        cin >> q;
        while(q--){
            int u, v;
            cin >> u >> v;
            if(u == v){
                cout << "The fleas meet at " << u << "." << endl;
                continue;
            }
            int d = bfs(u, v);
            if(d % 2 == 0){
                int ans = v;
                for(int i = 0; i < d/2; i++)
                    ans = parent[ans];
                cout << "The fleas meet at " << ans << "." << endl;
            }
            else{
                int ans = v;
                for(int i = 0; i < d/2; i++)
                    ans = parent[ans];
                cout << "The fleas jump forever between " << min(parent[ans], ans) << " and " << max(parent[ans], ans) << "." << endl;
            }

        }
    }

    return 0;
}
