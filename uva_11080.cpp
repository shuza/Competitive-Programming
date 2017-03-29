#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define MAXNODE 205

vector<int> edge[MAXNODE];
int visit[MAXNODE];

int BFS(int src){
    queue<int> q;
    int num1, num2;
    num1 = num2 = 0;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int i;
        for(i = 0; i < edge[u].size(); i++)
            if(visit[edge[u][i]] == 1)
                break;
        if(i == edge[u].size()){
            if(!visit[u]){
                num1++;
                visit[u] = 1;
            }
            for(i = 0; i < edge[u].size(); i++)
                if(!visit[edge[u][i]]){
                    visit[edge[u][i]] = 2;
                    num2++;
                    q.push(edge[u][i]);
                }
        }
        else{
            for(i = 0; i < edge[u].size(); i++)
                if(visit[edge[u][i]] == 2)
                    return -1;
            if(!visit[u]){
                visit[u] = 2;
                num2++;
            }
            for(i = 0; i < edge[u].size(); i++)
                if(!visit[edge[u][i]]){
                    visit[edge[u][i]] = 1;
                    num1++;
                    q.push(edge[u][i]);
                }
        }
    }
    if(num1 && num2)
        return min(num1, num2);
    if(num1)
        return num1;
    return num2;
}

void reset(){
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < MAXNODE; i++)
        edge[i].clear();
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        reset();
        int n, e;
        cin >> n >> e;
        while(e--){
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        int ans = 0;
        bool found = true;
        for(int i = 0; i < n; i++)
            if(!visit[i]){
                int a = BFS(i);
                if(a == -1){
                    found = false;
                    break;
                }
                else
                    ans += a;
            }
        if(found)
            cout << ans << endl;
        else
            puts("-1");
    }
    return 0;
}
