#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define MAXINT 1000
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int main()
{
    READ("in.txt");
//    WRITE("out.txt");
    int n;
    bool line = false;
    while(cin >> n){
        map<string, int> encode;
        vector<string> city;
        vector<int> g[MAXINT];
        while(n--){
            string a, b;
            cin >> a >> b;
            if(encode.find(a) == encode.end()){
                encode[a] = city.size();
                city.push_back(a);
            }
            if(encode.find(b) == encode.end()){
                encode[b] = city.size();
                city.push_back(b);
            }
            int u = encode[a];
            int v = encode[b];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        string a, b;
        cin >> a >> b;
        if(encode.find(a) == encode.end()){
            encode[a] = city.size();
            city.push_back(a);
        }
        if(encode.find(b) == encode.end()){
            encode[b] = city.size();
            city.push_back(b);
        }
        int src = encode[a];
        int des = encode[b];
        int par[MAXINT];
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(src);
        par[src] = src;
        while(!q.empty()){
            int u = q.front();  q.pop();
            if(u == des)
                break;
            for(int i = 0; i < g[u].size(); i++){
                int v = g[u][i];
                if(par[v] == -1){
                    par[v] = u;
                    q.push(v);
                }
            }
        }
        if(line)
            puts("");
        else
            line = true;
        if(par[des] == -1)
            puts("No route");
        else{
            vector<int> ans;
            ans.push_back(des);
            while(par[des] != des){
                ans.push_back(par[des]);
                des = par[des];
            }
            for(int i = ans.size()-1; i > 0; i--){
                int u = ans[i];
                int v = ans[i-1];
                cout << city[u] << " " << city[v] << endl;
            }
        }
    }
    return 0;
}
