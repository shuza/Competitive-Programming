#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXJ 32

vector<int> g[MAXJ];
int rout[MAXJ], visit[MAXJ], n;

void reset(){
    for(int i = 0; i < MAXJ; i++)
        g[i].clear();
    memset(rout, 0, sizeof(rout));
    memset(visit, 0, sizeof(visit));
}

void BFS(int u){
    int take[MAXJ] = {0};
    take[u] = 1;
    rout[u] = -1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();  q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(!take[v]){
                q.push(v);
                rout[v] = -1;
                take[v] = 1;
            }
        }
    }
}

void waycal(int u){
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(visit[v] == 0 && rout[v] != -1){
            visit[v] = 1;
            rout[v]++;
            waycal(v);
            visit[v] = 0;
        }
        else if(rout[v] != -1){
            BFS(v);
        }
    }
}

void dis(){
    for(int i = 0; i <= n; i++){
        if(i)
            cout << " ";
        cout << rout[i];
    }
    puts("");
}

int main()
{
    READ();
    int t, cas = 0;
    while(cin >> t){
        reset();
        n = -1;
        while(t--){
            int j, k;
            cin >> j >> k;
            g[j].push_back(k);
            n = max(n, max(j, k));
        }
        cout << "matrix for city " << cas++ << endl;
        for(int i = 0; i <= n; i++){
            memset(rout, 0, sizeof(rout));
            memset(visit, 0, sizeof(visit));
            visit[i] = 1;
            waycal(i);
            dis();
        }
    }
    return 0;
}
