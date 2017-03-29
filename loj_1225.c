#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int n,test,ans;
    int T,i;
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
        scanf("%ld", &n);
        test=n;
        ans=0;
        while(test!=0)
        {
            ans=ans*10+test%10;
            test/=10;
        }
        if(n==ans)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}
