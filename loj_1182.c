#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,r[32],ans;
    int T,i;
    unsigned short int t;
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
        ans=0;
        scanf("%d", &a);
        while(a>0)
        {
            t=a%2;
            if(t!=0)
                ans++;
            a/=2;
        }
        if(ans%2==0)
            printf("Case %d: even\n", i);
        else
            printf("Case %d: odd\n", i);
    }
    return 0;
}
