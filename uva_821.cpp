#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 102

vector<int> g[MAXNODE];

void reset(){
    for(int i = 0; i < MAXNODE; i++)
        g[i].clear();
}

int BFS(int u, int n){
    int dis[MAXNODE] = {0};
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
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += dis[i] - 1;
    return sum;
}

int main()
{
    int a, b, cas = 1;
    while(cin >> a >> b){
        if(!a && !b)
            break;
        reset();
        map<int, int> encode;
        int n = 0;
        while(a && b){
            if(encode.find(a) == encode.end())
                encode[a] = n++;
            if(encode.find(b) == encode.end())
                encode[b] = n++;
            a = encode[a];
            b = encode[b];
            g[a].push_back(b);
            cin >> a >> b;
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += BFS(i, n);
        int way = n * (n-1);
        double avg;
        avg = (double) sum / way;
        printf("Case %d: average length between pages = %.3lf clicks\n", cas++, avg);
    }
    return 0;
}
