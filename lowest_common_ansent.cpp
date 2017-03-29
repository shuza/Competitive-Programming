#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)

#define MAXNODE 17

vector<int> g[MAXNODE];
int L[MAXNODE];     // laveling
int T[MAXNODE];     // parent
int P[MAXNODE][4];     // spears table

void reset(){
    for(int i = 0; i < MAXNODE; i++)
        g[i].clear();
    memset(L, 0, sizeof(L));
    memset(T, 0, sizeof(T));
    memset(P, 0, sizeof(P));
}

void dfs(int from, int u, int dep){
    T[u] = from;
    L[u] = dep;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == from)
            continue;
        dfs(u, v, dep+1);
    }
}

void lac_init(int n){
    memset(P, -1, sizeof(P));
    for(int i = 0; i < n; i++)
        P[i][0] = T[i];
    for(int j = 1; (1 << j) < n; j++){
        for(int i = 0; i < n; i++){
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}

int lac_query(int n, int p, int q){
    if(L[p] < L[q]){
        int t = p;
        p = q;
        q = t;
    }
    int log = 1;
    while(1){
        int next = log+1;
        if((1 << next) > L[p])
            break;
        log++;
    }
    for(int i = log; i >= 0; i--)
        if(L[p] - (1 << i) >= L[q])
            p = P[q][i];
    if(q == p)
        return q;
    for(int i = log; i >= 0; i--)
        if(P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i],    q = P[q][i];
    return T[p];

}



int main()
{
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(4);
    g[4].push_back(5);
    g[5].push_back(6);
    g[6].push_back(7);
    g[6].push_back(14);
    g[1].push_back(8);
    g[8].push_back(9);
    g[9].push_back(10);
    g[10].push_back(11);
    g[11].push_back(12);
    g[11].push_back(15);
    g[12].push_back(13);
    g[12].push_back(16);

    dfs(0, 0, 0);
    lac_init(17);
    cout << "ans: " << lac_query(17, 2, 8);
    return 0;
}
