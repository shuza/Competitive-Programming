#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int T,i;
    unsigned int n,j;
    int a;
    long int ans;
    scanf("%u", &T);
    for(i=1;i<=T;i++)
    {
        scanf("%u", &n);
        ans=0;
        for(j=0;j<n;j++)
        {
            scanf("%d", &a);
            if(a>0)
                ans+=a;
        }
        printf("Case %u: %ld\n", i, ans);
    }
    return 0;
}
