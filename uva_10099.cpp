#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#define MAXNODE 101
#define MAXINT 32767

using namespace std;

int main()
{
    int cas = 1, N, R;
    freopen("in.txt", "r", stdin);
    while(cin >> N >> R)
    {
        if(N == 0 && R == 0)
            break;
        int dp[MAXNODE][MAXNODE];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < R; i++)
        {
            int u , v, w;
            cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = w;
        }
        for(int i = 1; i <= N; i++)
            dp[i][i] = MAXINT;
        for(int k = 1; k <= N; k++)
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));
        int src, des, tourist;
        cin >> src >> des >> tourist;
        int trip = tourist / (dp[src][des] - 1);
        if(tourist % (dp[src][des] - 1) > 0)
            trip++;
        cout << "Scenario #" << cas++ << endl;
        cout << "Minimum Number of Trips = " << trip << endl <<endl;
    }
    return 0;
}
