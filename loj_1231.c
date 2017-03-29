#include <stdio.h>
#include <stdlib.h>

int A[50], C[50], n;
long dp[50][20][1001];

long fun(int make, int i, int take)
{
    int ans1, ans2;
    ans1 = ans2 = 0;
    if(make == 0)
        return 1;
    if(i == n)
        return 0;
    if(dp[i][take][make] != -1)
        return dp[i][take][make];
    if(take < C[i] && make - A[i] >= 0)
        ans1 = fun(make - A[i], i, take + 1) % 100000007;
    if(i + 1 < n)
        ans2 = fun(make, i + 1, 0) % 100000007;
    return dp[i][take][make] = (ans1 + ans2) % 100000007;
}

int main()
{
    int T, count = 1, i, K;
    long ans;
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(count <= T)
    {
        scanf("%d %d", &n, &K);
        for(i = 0; i < n; i++)
            scanf("%d", &A[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &C[i]);
        memset(dp, -1, sizeof(dp));
        ans = fun(K, 0, 0);
        printf("Case %d: %ld\n", count, ans);
        count++;
    }
    return 0;
}
