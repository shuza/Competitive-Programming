#include <iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX_NODE 100002
using namespace std;

vector<int>g[MAX_NODE], cost[MAX_NODE];
int d[MAX_NODE], parent[MAX_NODE];
struct node{
    int u, w;
    node(int a, int b){u=a; w=b;}
    bool operator < (const node& p) const{ return w > p.w; }
};

int shortest_path(int src, int destenation){
    memset(d, 63, sizeof(d));
    memset(parent, -1, sizeof(parent));
    priority_queue<node> q;
    q.push(node(src, 0));
    d[src] = 0;

    while(!q.empty()){
        node top = q.top();
        q.pop();
        int u = top.u;
        if(u == destenation)
            return d[destenation];
        for(int i = 0; i<g[u].size(); i++){
            int v = g[u][i];
            if(d[u]+cost[u][i] < d[v]){
                d[v] = d[u]+cost[u][i];
                parent[v] = u;
                q.push(node(v, d[v]));
            }
        }
    }
    return -1;
}


int main()
{
    int n, e;
    cout << "Enter node & edge number: ";
    cin >> n >> e;
    cout << "Enter edge as srource distenation distance\n";
    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int src, des;
    cout << "Enter source & distenation: ";
    cin >> src >> des;
    int dis = shortest_path(src, des);
    if(dis == -1){
        cout << "No path" << endl;
        return 0;
    }
    int u = des;
    vector<int> path;
    while(u != -1){
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(), path.end());
    cout << "distance: " << dis << "\npath: ";
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    /*
    cout << "distance: " << dis << "\npath: ";
    for(int i = path.size(); i > 0; i--){
        cout << path[i-1] << " ";
    }
    */
    return 0;
}
