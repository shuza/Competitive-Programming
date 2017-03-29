#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int n;
    int ans,input;
    while(scanf("%ld", &n)==1)
    {
        if(n==0)
            break;
        ans=n;
        while(ans%10!=ans)
        {
            n=ans;
            ans=0;
            while(n!=0)
            {
                ans+=n%10;
                n/=10;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
