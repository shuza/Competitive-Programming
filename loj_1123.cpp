#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXNODE 5

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
    int t, cas = 1;
    cin >> t;
    while(t--){
        vector<data> edge;
        int N, W, i;
        cin >> N >> W;
        int largeW = -1;
        cout << "Case " << cas++ << ":" << endl;
        for(i = 1; i < N - 1; i++){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
            puts("-1");
        }
        long ans = 0;
        while(i++ <= W){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
            if(test.w > largeW && ans > 0){
                cout << ans << endl;
                continue;
            }
            vector<data> v;
            sort(edge.begin(), edge.end());
            setParent(N);
            int taken = 0;
            long cost = 0;
            for(int j = 0; j < edge.size(); j++){
                int a = getParent(edge[j].u);
                int b = getParent(edge[j].v);
                if(a != b){
                    parent[a] = b;
                    taken++;
                    cost += edge[j].w;
                    v.push_back(edge[j]);
                    if(taken == N - 1){
                        edge = v;
                        largeW = v[v.size()-1].w;
                        ans = cost;
                        break;
                    }
                }
            }
            if(taken == N - 1)
                cout << cost << endl;
            else
                puts("-1");
        }
    }
    return 0;
}
