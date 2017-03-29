#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#define LL long long

#define NMAX 30002

using namespace std;

vector<int> edge[NMAX], cost[NMAX];
LL ans;

void reset(){
    for(int i = 0; i < NMAX; i++)
        edge[i].clear(), cost[i].clear();
    ans = 0;
}

LL BFS(int u){
    LL dis[NMAX] = {0};
    int visit[NMAX] = {0};
    int z = u;
    queue<int> q;
    q.push(u);
    visit[u] = 1;
    while(!q.empty()){
        u = q.front();  q.pop();
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i];
            int w = cost[u][i];
            if(!visit[v]){
                q.push(v);
                visit[v] = 1;
                dis[v] = dis[u] + w;
                if(dis[v] > ans){
                    ans = dis[v];
                    z = v;
                }
            }
        }
    }
    return z;
}

int main()
{
    int t, casNo = 1;
    cin >> t;
    while(t--){
        reset();
        int N;
        cin >> N;
        for(int i = 0; i < N - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge[u].push_back(v);
            cost[u].push_back(w);
            edge[v].push_back(u);
            cost[v].push_back(w);
        }
        int u = BFS(0);
        u = BFS(u);
        cout << "Case " << casNo++ << ": " << ans << endl;
    }
    return 0;
}
