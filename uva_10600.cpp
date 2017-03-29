#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define INF (1<<30)
#define MAXNODE 105

struct data{
    int u, v, w;
    bool operator < (const data& p) const {
        return w < p.w;
    }
};

vector<data> edge;
vector<int> next;
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

long MST(int n, int a){
    setParent(n);
    long ans = 0;
    int taken = 0;
    for(int i = 0; i < edge.size(); i++)
        if(i != a){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
                ans += edge[i].w;
                next.push_back(i);
            }
            if(taken == n-1)
                break;
        }
    if(taken < n-1)
        return -1;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        edge.clear();
        next.clear();
        int n, m;
        cin >> n >> m;
        while(m--){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        long ans1, ans2;
        ans1 = MST(n, edge.size()+2);
        ans2 = INF;
        vector<int>v;
        v = next;
        for(int i = 0; i < v.size(); i++){
            long a = MST(n, v[i]);
            if(a < ans2 && a != -1)
                ans2 = a;
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
