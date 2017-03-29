#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXNODE 22

vector<int> relation[MAXNODE];

void reset(){
    for(int i = 0; i < MAXNODE; i++)
        relation[i].clear();
}

int BFS(int src, int des){
    int dis[MAXNODE] = {0};
    queue<int> q;
    q.push(src);
    while(!q.empty() && dis[des] == 0){
        int u = q.front();
        q.pop();
        for(int i = 0; i < relation[u].size(); i++){
            int v = relation[u][i];
            if(!dis[v]){
                q.push(v);
                dis[v] = dis[u] + 1;
            }
        }
    }
    return dis[des];
}



int main()
{
    freopen("in.txt", "r", stdin);
    int n, cas = 1;
    while(cin >> n){
        reset();
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            relation[1].push_back(a);
            relation[a].push_back(1);
        }
        for(int i = 2; i <= 19; i++){
            cin >> n;
            while(n--){
                int b;
                cin >> b;
                relation[i].push_back(b);
                relation[b].push_back(i);
            }
        }
        cin >> n;
        cout << "Test Set #" << cas++ << endl;
        while(n--){
            int src, des;
            cin >> src >> des;
            int ans = BFS(src, des);
            printf("%2d to %2d: %d\n", src, des, ans);
        }
        puts("");
    }
    return 0;
}
