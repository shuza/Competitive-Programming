#include <stdio.h>
#include <stdlib.h>

int cost[20][3], N, dp[20][3];

int fun(int build_no, int color)
{
    int ans1, ans2;
    if(build_no == N)
        return 0;
    if(dp[build_no][color] != -1)
        return dp[build_no][color];
    ans1 = cost[build_no][color] + fun(build_no + 1, (color + 1) % 3);
    ans2 = cost[build_no][color] + fun(build_no + 1, (color + 2) % 3);
    if(ans1 < ans2)
        return dp[build_no][color] = ans1;
    return dp[build_no][color] = ans2;
}

int main()
{
    int T, cas = 1, i, ans;
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(cas <= T)
    {
        scanf("%d", &N);
        for(i = 0; i < N; i++)
            scanf("%d%d%d", &cost[i][0], &cost[i][1], &cost[i][2]);
        memset(dp, -1, sizeof(dp));
        ans = fun(0, 0);
        i = fun(0, 1);
        if(i < ans)
            ans = i;
        i = fun(0, 2);
        if(i < ans)
            ans = i;
        printf("Case %d: %d\n", cas, ans);
        cas++;
    }
    return 0;
}
