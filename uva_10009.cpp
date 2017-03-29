#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 28

int main()
{
    READ();
    bool line = false;
    int t;
    cin >> t;
    while(t--){
        if(line)
            puts("");
        line = true;
        vector<int> g[MAXNODE];
        int n, q;
        cin >> n >> q;
        while(n--){
            int u, v;
            string s1, s2;
            cin >> s1 >> s2;
            u = s1[0] - 'A';
            v = s2[0] - 'A';
            g[u].push_back(v);
            g[v].push_back(u);
        }
        while(q--){
            string s1, s2;
            cin >> s1 >> s2;
            int u, v;
            v = s1[0] - 'A';
            u = s2[0] - 'A';
            s1 = "";
            int p[MAXNODE];
            for(int i = 0; i < MAXNODE; i++)
                p[i] = i;
            p[u] = -1;
            queue<int> q;
            q.push(u);
            while(!q.empty()){
                u = q.front();  q.pop();
                if(u == v)
                    break;
                for(int i = 0; i < g[u].size(); i++){
                    int v = g[u][i];
                    if(p[v] == v){
                        p[v] = u;
                        q.push(v);
                    }
                }
            }
            string path = "";
            s1 = v + 'A';
            path = path + s1;
            while(p[v] != -1){
                s1 = p[v] + 'A';
                path = path + s1;
                v = p[v];
            }
            cout << path << endl;
        }
    }
    return 0;
}
