#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

vector <int> G[200];
int color[200];

bool DFS(){
    int i;
    memset(color, 0, sizeof(color));
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int u = Q.front();
        for(i = 0; i < G[u].size(); i++)
            if(color[G[u][i]] == 1)
                break;
        if(i == G[u].size()){
            color[u] = 1;
            for(i = 0; i < G[u].size(); i++)
                if(color[G[u][i]] == 0){
                    color[G[u][i]] = 2;
                    Q.push(G[u][i]);
                }
        }
        else{
            for(i = 0; i < G[u].size(); i++)
                if(color[G[u][i]] == 2)
                    break;
            if(i != G[u].size())
                return false;
            color[u] = 2;
            for(i = 0; i < G[u].size(); i++)
                if(color[G[u][i]] == 0){
                    color[G[u][i]] = 1;
                    Q.push(G[u][i]);
                }
        }
        Q.pop();
    }
    return true;
}

int main()
{
    int nodeNum;
    cin >> nodeNum;
    while(nodeNum != 0){
        int line, a, b, i, j;
        bool ans = true;
        cin >> line;
        for(i = 0; i < line; i++){
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        ans = DFS();
        if(ans)
            cout << "BICOLORABLE.";
        else
            cout << "NOT BICOLORABLE.";
        cout << endl;
        for(i = 0; i < 200; i++)
            G[i].clear();
        cin >> nodeNum;
    }
    return 0;
}