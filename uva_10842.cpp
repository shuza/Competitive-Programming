#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXNODE 105

struct data{
    int u, v, w;
    bool operator < (const data& p) const {
        return w > p.w;
    }
};

int parent[MAXNODE];

void setParent(int n){
    for(int i = 0; i <= n; i++)
        parent[i] = i;
}

int getParent(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = getParent(parent[a]);
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<data> edge;
        while(m--){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        int taken = 0;
        int ans = 0;
        setParent(n);
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                ans = edge[i].w;
            }
            if(taken == n-1)
                break;
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
