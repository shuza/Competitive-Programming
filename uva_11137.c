#include <stdio.h>
#include <stdlib.h>

int coin[21];
long long dp[21][10000];

long long fun(int make, int i)
{
    long long ans = 0;
    if(make == 0)
        return 1;
    if(i >= 21)
        return 0;
    if(dp[i][make] != -1)
        return dp[i][make];
    if(make - coin[i] >= 0)
        ans = fun(make - coin[i], i);
    ans += fun(make, i + 1);
    return dp[i][make] = ans;
}

int main()
{
    int i, make;
    for(i = 1; i <= 21; i++)
        coin[i - 1] = i * i * i;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &make) != EOF)
    {
        printf("%lld\n", fun(make, 0));
    }
    return 0;
}
