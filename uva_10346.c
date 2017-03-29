#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, ans ;
    while(scanf("%d %d", &n, &k)!=EOF)
    {
        ans=n;
        while(n>=k)
        {
            ans+=n/k;
            n=(n/k)+(n%k);
        }
        printf("%d\n", ans);
    }
    return 0;
}
