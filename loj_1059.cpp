#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define MAXNODE 10005

using namespace std;

struct data{
    int u, v, w;
    bool operator < (const data& p) const{
        return w < p.w;
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    cin >> t;
    while(t--){
        int N, M, airport;
        cin >> N >> M >> airport;
        vector<data> edge;
        while(M--){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        setParent(N);
        sort(edge.begin(), edge.end());
        int taken = 0;
        vector<data>v;
        unsigned long long cost = 0;
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
                cost += edge[i].w;
                v.push_back(edge[i]);
            }
            if(taken == N - 1)
                break;
        }
        if(taken < N - 1){
            taken = N - taken;
            cost += airport * taken;
        }
        else{
            taken = 1;
            cost += airport;
        }
        unsigned long long c1 = 0;
        int t1 = 0;
        for(int i = 0; i < v.size(); i++){
            if(edge[i].w >= airport){
                c1 += edge[i].w;
                t1++;
            }
        }
        taken += t1;
        cost += airport*t1 - c1;
        cout << "Case " << cas++ << ": " << cost << " " << taken << endl;
    }
    return 0;
}
