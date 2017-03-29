#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
#define MAXN 20005

int main()
{
    READ("in.txt");
    WRITE("out.txt");
    int n, m;
    while(cin >> n >> m){
        if(!(n || m))
            break;
        int head[MAXN], knight[MAXN];
        for(int i = 0; i < n; i++)
            cin >> head[i];
        for(int i = 0; i < m; i++)
            cin >> knight[i];
        if(m < n){
            puts("Loowater is doomed!");
        }
        else{
            sort(head, head+n);
            sort(knight, knight+m);
            long long cost = 0;
            int cut = 0;
            for(int i = 0; i < m && cut < n; i++)
                if(knight[i] >= head[cut]){
                    cost += knight[i];
                    cut++;
                }
            if(cut == n)
                cout << cost << endl;
            else
                puts("Loowater is doomed!");
        }
    }
    return 0;
}
