#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, cas = 1, i, ans, fartil, n, test;
    char field[100];
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %s", &n, field);
        ans = 0;
        for(i = 0; i < n; i++)
        {
            test = 0;
            while(field[i] == '.' && i < n)
            {
                test++;
                i++;
            }
            ans += test / 3;
            if(test % 3 == 1 && i < n - 1 && field[i + 1] == '.')
                i++;
            if(test % 3 != 0)
                ans++;
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
