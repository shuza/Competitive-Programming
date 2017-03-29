#include <stdio.h>
#include <stdlib.h>

int prime[33] = {0, 0, 1, 1, 0 ,1, 0 ,1, 0 ,0 ,0 ,1, 0 ,1, 0 ,0 ,0 ,1, 0 ,1, 0 ,0 ,0 ,1, 0 ,0 ,0 ,0 ,0 ,1, 0 ,1, 0 ,};
int visit[17] = {0};
int ans[16];

int main()
{
    int size, count = 0;
    while(scanf("%d", &size) != EOF)
    {
        if(count != 0)
            printf("\n");
        printf("Case %d:\n", ++count);
        ans[0] = 1;
        backtrack(size, 1);
    }
    return 0;
}

void backtrack(int size, int count)
{
    int i;
    if(count == size)
    {
        printf("1");
        for(i = 1; i < size; i++)
            printf(" %d", ans[i]);
        printf("\n");
        return;
    }
    for(i = 2; i <= size; i++)
    {
        if(visit[i] == 0)
        {
            if(is_prime(count - 1, i, size))
            {
                visit[i] = 1;
                ans[count] = i;
                backtrack(size, count + 1);
                visit[i] = 0;
            }
        }
    }
}

int is_prime(int count, int i, int size)
{
    if(count == size - 2)
    {
        if(prime[ans[count] + i] && prime[1 + i])
            return 1;
    }
    else if(prime[ans[count] + i])
        return 1;
    return 0;
}
