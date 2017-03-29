#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, cas = 1;
    long rungs[100001], ans, test, n, i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%ld", &n);
        ans = rungs[0] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%ld", &rungs[i]);
            if(rungs[i] - rungs[i - 1] > ans)
                ans = rungs[i] - rungs[i - 1];
        }
        test = ans;
        for(i = 1; i <= n; i++)
        {
            if(rungs[i] - rungs[i - 1] == test)
                test--;
            else if((rungs[i] - rungs[i - 1] > test) || (test <= 0 && i != n))
            {
                ans = test = ans + 1;
                i = 1;
            }
        }
        printf("Case %d: %ld\n", cas++, ans);
    }
    return 0;
}
