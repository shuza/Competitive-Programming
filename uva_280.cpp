#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAXINT 10000

vector<int> g[MAXINT];
int visit[MAXINT];

void reset(){
    for(int i = 0; i < MAXINT; i++)
        g[i].clear();
}

int BFS(int src, int n){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u = q.front();  q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!visit[v]){
                visit[v] = 1;
                q.push(v);
                n--;
            }
        }
    }
    return n;
}

int main()
{
    READ("in.txt");
    int n;
    while(cin >> n){
        if(!n)  break;
        reset();
        int u;
        while(cin >> u){
            if(!u)  break;
            int v;
            while(cin >> v){
                if(v == 0)
                    break;
                g[u].push_back(v);
            }
        }
        int q;
        cin >> q;
        while(q--){
            int src;
            cin >> src;
            memset(visit, 0, sizeof(visit));
            int node = BFS(src, n);
            cout << node;
            for(int i = 1; i <= n && node; i++)
                if(!visit[i]){
                    cout << " " << i;
                    node--;
                }
            puts("");
        }
    }
    return 0;
}
