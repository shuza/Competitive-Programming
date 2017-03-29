#include <stdio.h>
#include <stdlib.h>

int input[200][200], element[200], N;
long dp[200][200];

long int fun(int row, int col)
{
    int ans1, ans2;
    if(row == 2*N-1 || col >= element[row] || col < 0)
        return 0;
    if(dp[row][col] != -1)
        return dp[row][col];
    if(row < N - 1)
    {
        ans1 = input[row][col] + fun(row + 1, col + 1);
        ans2 = input[row][col] + fun(row + 1, col);
    }
    else
    {
        ans1 = input[row][col] + fun(row + 1, col);
        ans2 = input[row][col] + fun(row + 1, col - 1);
    }
    if(ans2 > ans1)
        return dp[row][col] = ans2;
    return dp[row][col] = ans1;
}

int main()
{
    int T, cas = 1, i, j;
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        memset(dp, -1, sizeof(dp));
        memset(element, 0, sizeof(element));
        for(i = 0; i < N; i++)
        {
            for(j = 0; j <= i; j++)
                scanf("%d", &input[i][j]);
            element[i] = i + 1;
        }
        for(i = 1; i < N; i++)
        {
            for(j = 0; j < N - i; j++)
                scanf("%d", &input[N + i - 1][j]);
            element[N + i -1] = j;
        }
        printf("Case %d: %ld\n", cas++, fun(0, 0));
    }
    return 0;
}
