#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define INF (1<<30)
#define eps (1e-11)
using namespace std;

#define MAXNODE 20002

vector<int> G[MAXNODE];
vector<int>nodeList;
bool visit[MAXNODE];

int bfs(int src){
    int level[2] = {0};
    int currentLeve = 0;
    vector<int>v1, v2;
    v1.push_back(src);
    visit[src] = true;
    level[currentLeve]++;
    while(!v1.empty()){
        currentLeve = (currentLeve+1) % 2;
        for(int i = 0; i < v1.size(); i++){
            int a = v1[i];
            for(int j = 0; j < G[a].size(); j++){
                if(!visit[G[a][j]]){
                    level[currentLeve]++;
                    v2.push_back(G[a][j]);
                    visit[G[a][j]] = true;
                }
            }
        }
        v1.clear();
        v1 = v2;
        v2.clear();
    }
    return max(level[0], level[1]);
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    cin >> t;
    while(t--){
        for(int i = 0; i < MAXNODE; i++){
            G[i].clear();
            visit[i] = false;
        }
        bool nodehas[MAXNODE] = {false};
        int n, l = 0;
        cin >> n;
        while(n--){
            int u, v;
            cin >> u >> v;
            if(!nodehas[u]){
                nodehas[u] = true;
                nodeList.push_back(u);
            }
            if(!nodehas[v]){
                nodehas[v] = true;
                nodeList.push_back(v);
            }
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        for(int i = 0; i < nodeList.size(); i++){
            int u = nodeList[i];
            if(!visit[u])
                ans += bfs(u);
        }
        cout << "Case " << cas++ << ": " << ans << endl;
        nodeList.clear();
    }
    return 0;
}
