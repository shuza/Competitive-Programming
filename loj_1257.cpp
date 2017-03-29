#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAXNODE 30002
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

vector<int> edge[MAXNODE], cost[MAXNODE];
int dis[MAXNODE];

void reset(int n){
    for(int i = 0; i < n; i++)
        edge[i].clear(), cost[i].clear();
}

int BFS(int u){
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    int ans = 0;
    int src = u;
    while(!q.empty()){
        u = q.front();  q.pop();
        for(int i = 0; i < edge[u].size(); i++){
            int v = edge[u][i];
            int w = cost[u][i];
            if(dis[v] == -1){
                dis[v] = dis[u] + w;
                q.push(v);
                if(dis[v] > ans){
                    ans = dis[v];
                    src = v;
                }
            }
        }
    }
    return src;
}

int main()
{
    READ();
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--){
        reset(MAXNODE);
        int n;
        cin >> n;
        for(int i = 0; i < n-1; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge[u].push_back(v);
            cost[u].push_back(w);
            edge[v].push_back(u);
            cost[v].push_back(w);
        }
        int x = BFS(0);
        x = BFS(x);
        int dis_x[MAXNODE];
        memset(dis_x, -1, sizeof(dis_x));
        queue<int> q;
        q.push(x);
        dis_x[x] = 0;
        while(!q.empty()){
            x = q.front();  q.pop();
            for(int i = 0; i < edge[x].size(); i++){
                int v = edge[x][i];
                int w = cost[x][i];
                if(dis_x[v] == -1){
                    dis_x[v] = dis_x[x] + w;
                    q.push(v);
                }
            }
        }
        printf("Case %d:\n", caseno++);
        for(int i = 0; i < n; i++){
            printf("%d\n", max(dis[i], dis_x[i]));
        }
    }
    return 0;
}
