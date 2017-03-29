#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXFRND 2505

vector<int> g[MAXFRND];
int dis[MAXFRND];

void reset(){
    for(int i = 0; i < MAXFRND; i++)
        g[i].clear();
    memset(dis, 0, sizeof(dis));
}

void BFS(int u){
    memset(dis, 0, sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u] = 1;
    while(!q.empty()){
        u = q.front();  q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!dis[v]){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    while(cin >> n){
        reset();
        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            while(m--){
                int a;
                cin >> a;
                g[i].push_back(a);
            }
        }
        int t;
        cin >> t;
        while(t--){
            int src;
            cin >> src;
            BFS(src);
            sort(dis, dis+n);
            int i = 0;
            while(i < n && (!dis[i] || dis[i] == 1))
                i++;
            if(i == n)
                puts("0");
            else{
                int m = 1, d = dis[i];
                while(i < n){
                    i++;
                    int test = 1;
                    while(i < n && dis[i-1] == dis[i]){
                        test++;
                        i++;
                    }
                    if(test > m){
                        m = test;
                        d = dis[i-1];
                    }
                }
                cout << m << " " << d-1 << endl;
            }
        }
    }
    return 0;
}
