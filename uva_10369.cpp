#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MAXNODE 505
#define eps 1e-11

struct data{
    int u, v;
    double w;
    bool operator < (const data& p) const{
        return w+eps < p.w;
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
    int t;
    cin >> t;
    while(t--){
        int S, P;
        int x[MAXNODE], y[MAXNODE];
        cin >> S >> P;
        for(int i = 0; i < P; i++)
            cin >> x[i] >> y[i];
        vector<data> edge;
        for(int i = 0; i < P; i++)
            for(int j = 0; j < P; j++){
                data test;
                test.u = i;
                test.v = j;
                double d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                test.w = sqrt(d);
                edge.push_back(test);
            }
        setParent(P);
        double ans = eps;
        int taken = 0;
        sort(edge.begin(), edge.end());
        for(int i = 0; i < edge.size() && taken < P-S; i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                if(edge[i].w > ans+eps)
                    ans = edge[i].w;
                taken++;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
