#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAXNODE 4

using namespace std;

struct data{
    int u, v, w;
    bool operator < (const data& p) const {
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
    int t, cas = 1;
    cin >> t;
    while(t--){
        int N;
        vector<data> edge;
        cin >> N;
        while(true){
            data test;
            cin >> test.u >> test.v >> test.w;
            if(!(test.u || test.v || test.w))
                break;
            edge.push_back(test);
        }
        sort(edge.begin(), edge.end());
        long mincost = 0;
        int taken = 0;
        setParent(N);
        for(int i = 0; i < edge.size(); i++){
            int a, b;
            a = getParent(edge[i].u);
            b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
                mincost += edge[i].w;
            }
            if(taken == N)
                break;
        }
        setParent(N);
        taken = 0;
        long maxcost = 0;
        for(int i = edge.size()-1; i >= 0; i--){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
                maxcost += edge[i].w;
            }
            if(taken == N)
                break;
        }
        cout << "Case " << cas++ << ": ";
        if((mincost+maxcost)%2 == 0)
            cout << (mincost+maxcost)/2 << endl;
        else
            cout << (mincost+maxcost) << "/2" << endl;
    }
    return 0;
}
