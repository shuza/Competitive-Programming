#include <stdio.h>
#include <stdlib.h>

int N, K, visit[26], print;
char latter[26], str[26];

void fun(int n)
{
    int col = 0;
    if(n == N)
    {
        str[n] = '\0';
        printf("%s\n", str);
        print++;
        return;
    }
    while(col < N)
    {
        if(visit[col] == 0)
        {
            visit[col] = 1;
            str[n] = latter[col];
            fun(n + 1);
            visit[col] = 0;
        }
        if(print == K)
            return;
        col++;
    }
}

int main()
{
    int T, cas = 0;
    for(T = 65; T <= 90; T++)
        latter[cas++] = (char) T;
    cas = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &K);
        memset(visit, 0, sizeof(visit));
        print = 0;
        printf("Case %d:\n", cas++);
        fun(0);
    }
    return 0;
}
