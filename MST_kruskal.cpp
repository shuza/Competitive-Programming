        /*********      LOJ - 1041
                algo: Kruskal (MST)
        **********/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

#define MAXNODE 55

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
//    freopen("in.txt", "r", stdin);
    int t, cas = 1;
    cin >> t;
    while(t--){
        map<string, int>encode;
        vector<data> edge;
        int N, node = 1;
        cin >> N;
        while(N--){
            string s1, s2;
            data test;
            cin >> s1 >> s2 >> test.w;
            if(encode[s1] < 1)
                encode[s1] = node++;
            if(encode[s2] < 1)
                encode[s2] = node++;
            test.u = encode[s1];
            test.v = encode[s2];
            edge.push_back(test);
        }
        long cost = 0;
        N = 0;
        setParent(node);
        sort(edge.begin(), edge.end());
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                cost += edge[i].w;
                N++;
            }
            if(N == node - 2)
                break;
        }
        cout << "Case " << cas++ << ": ";
        if(N == node - 2)
            cout << cost << endl;
        else
            puts("Impossible");
    }
    return 0;
}
