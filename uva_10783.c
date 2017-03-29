#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int T,i,a,b;
    unsigned int ans;
    scanf("%hu", &T);
    for(i=1;i<=T;i++)
    {
        scanf("%hu %hu", &a, &b);
        if(a%2==0)
            a++;
        ans=0;
        while(a<=b)
        {
            ans+=a;
            a+=2;
        }
        printf("Case %hu: %u\n", i, ans);
    }
    return 0;
}
