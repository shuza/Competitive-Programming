#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAXFIELD 2005

vector<int> g[MAXFIELD];
int color[MAXFIELD], b, c;

void init(){
    for(int i = 0; i < MAXFIELD; i++){
        g[i].clear();
        color[i] = 0;
    }
}

void bicolouring(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;
    int one = 1, two = 0;
    while(!q.empty()){
        u = q.front();  q.pop();
        int i;
        for(i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(color[v] == 1)
                break;
        }
        if(i == g[u].size()){
            if(!color[u]){
                color[u] = 1;
                one++;
            }
            for(i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(!color[v]){
                    color[v] = 2;
                    two++;
                    q.push(v);
                }
            }
        }
        else{
            for(i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(color[v] == 2)
                    break;
            }
            if(i == g[u].size()){
                if(!color[u]){
                    color[u] = 2;
                    two++;
                }
                for(i = 0; i < g[u].size(); i++){
                    int v = g[u][i];
                    if(!color[v]){
                        color[v] = 1;
                        one++;
                        q.push(v);
                    }
                }
            }
            else{
                for(int i = 0; i < g[u].size(); i++){
                    int v = g[u][i];
                    if(!color[v]){
                        color[v] = 3;
                    }
                }
            }
        }
    }
    if(c < b){
        u = b;
        b = c;
        c = u;
    }
    b -= min(one, two);
    c -= max(one, two);
}

int main()
{
    READ("in.txt");
    int  t;
    cin >> t;
    while(t--){
        init();
        int n;
        cin >> b >> c >> n;
        int field = b + c;
        while(n--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i <= field && (b > 0 || c > 0); i++){
            if(!color[i]){
                bicolouring(i);
            }
        }
        if(b <= 0 && c <= 0)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
