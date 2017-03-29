#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXNODE 55

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
//    freopen("in.txt", "r", stdin);
    int t, cas = 1;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        long total = 0;
        vector<data> edge;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                data test;
                test.u = i;
                test.v = j;
                cin >> test.w;
                if(test.w){
                    total += test.w;
                    edge.push_back(test);
                }
            }
        }
        sort(edge.begin(), edge.end());
        setParent(N);
        int taken = 0;
        long cost = 0;
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                cost += edge[i].w;
                taken++;
            }
            if(taken == N - 1)
                break;
        }
        if(taken == N - 1)
            cost = total - cost;
        else
            cost = -1;
        cout << "Case " << cas++ << ": " << cost << endl;
    }
    return 0;
}
