#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 32

vector<int> g[MAXNODE];

void reset(){
    for(int i = 0; i < MAXNODE; i++)
        g[i].clear();
}

int BFS(int src, int des){
    int dis[MAXNODE] = {0};
    dis[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        src = q.front();    q.pop();
        if(src == des)
            return dis[src] - 1;
        for(int i = 0; i < g[src].size(); i++){
            int v = g[src][i];
            if(!dis[v]){
                dis[v] = dis[src] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    int t, cas = 1;
    cin >> t;
    puts("SHIPPING ROUTES OUTPUT\n");
    while(t--){
        reset();
        int n, m, p;
        cin >> n >> m >> p;
        int nodNum = 0;
        map<string, int> encode;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            encode[s] = nodNum++;
        }
        while(m--){
            string s1, s2;
            cin >> s1 >> s2;
            int u, v;
            u = encode[s1];
            v = encode[s2];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout << "DATA SET  " << cas++ << endl << endl;
        while(p--){
            string s1, s2;
            int ans, cost;
            cin >> cost >> s1 >> s2;
            if(encode.find(s1) == encode.end())
                encode[s1] = nodNum++;
            if(encode.find(s2) == encode.end())
                encode[s2] = nodNum++;
            int u, v;
            u = encode[s1];
            v = encode[s2];
            ans = BFS(u, v);
            if(ans > -1)
                cout << "$" << (ans * cost * 100) << endl;
            else
                puts("NO SHIPMENT POSSIBLE");
        }
        puts("");
    }
    puts("END OF OUTPUT");
    return 0;
}
