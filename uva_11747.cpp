#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAXNODE 1005

using namespace std;

struct data{
    int u, v;
    unsigned long w;
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
    int n, m;
    while(cin >> n >> m){
        if(!(n || m))
            break;
        vector<data> edge;
        for(int i = 1; i <= m; i++){
            data test;
            cin >> test.u >> test.v >> test.w;
            edge.push_back(test);
        }
        setParent(n);
        sort(edge.begin(), edge.end());
        int taken = 0;
        vector<int> ans;
        for(int i = 0; i < edge.size(); i++){
            int a = getParent(edge[i].u);
            int b = getParent(edge[i].v);
            if(a != b){
                parent[a] = b;
                taken++;
            }
            else
                ans.push_back(edge[i].w);
            if(taken == n - 1){
                while(++i < edge.size())
                    ans.push_back(edge[i].w);
                break;
            }
        }
        if(ans.size()){
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++)
                if(i)
                    cout << " " << ans[i];
                else
                    cout << ans[i];
            cout << endl;
        }
        else
            puts("forest");
    }
    return 0;
}
