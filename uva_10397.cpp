#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define MAXNODE 755
#define eps 1e-11

struct data{
    int u, v;
    double w;
    bool operator < (const data& p) const{
        return w+eps < p.w;
    }
};

int parent[MAXNODE];

int setParent(int n){
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
    int N;
    while(cin >> N){
        int x[MAXNODE], y[MAXNODE];
        for(int i = 0; i < N; i++)
            cin >> x[i] >> y[i];
        setParent(N);
        int m;
        cin >> m;
        while(m--){
            int a, b;
            cin >> a >> b;
            parent[getParent(a)] = getParent(b);
        }
        vector<data> edge;
        for(int i = 0; i < N; i++)
            for(int j = i+1; j < N; j++){
                data test;
                test.u = i+1;
                test.v = j+1;
                long s = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                test.w = sqrt(s);
                edge.push_back(test);
            }
        sort(edge.begin(), edge.end());
        double cost = 0;
        int taken = 0;
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
                cost += edge[i].w;
            }
            if(taken == N - 1)
                break;
        }
        printf("%.2lf\n", cost);
    }
    return 0;
}
