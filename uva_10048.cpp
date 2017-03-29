#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXNODE 102

struct data{
    int u, v, w;
    bool operator < (const data& p) const {
        return w < p.w;
    }
};

int parent[MAXNODE];
vector<data> edge;

void setParent(int n){
    for(int i = 0; i <= n; i++)
        parent[i] = i;
}

int getParent(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = getParent(parent[a]);
}

long MST(int src, int des, int n){
    setParent(n);
    long ans = 0;
    int taken = 0;
    for(int i = 0; i < edge.size(); i++){
        if(getParent(src) == getParent(des))
            return ans;
        int a = getParent(edge[i].u);
        int b = getParent(edge[i].v);
        if(a != b){
            parent[a] = b;
            taken++;
            ans = edge[i].w;
        }
        if(taken == n-1)
            break;
    }
    if(getParent(src) == getParent(des))
        return ans;
    return -1;
}

int main()
{
    int n, m, q, cas = 1;
    bool line = false;
    while(cin >> n >> m >> q){
        if(!(n || m || q))
            break;
        edge.clear();
        while(m--){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        if(line)
            puts("");
        else
            line = true;
        cout << "Case #" << cas++ << endl;
        while(q--){
            int src, des;
            cin >> src >> des;
            long ans = MST(src, des, n);
            if(ans == -1)
                puts("no path");
            else
                cout << ans << endl;
        }
    }
    return 0;
}
