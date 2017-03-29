#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int T=1,x;
    int ans;
    unsigned int N,i;
    while(scanf("%u", &N))
    {
        if(N==0)
            break;
        ans=0;
        for(i=0;i<N;i++)
        {
            scanf("%hu", &x);
            if(x==0)
                ans--;
            else
                ans++;
        }
        printf("Case %hu: %d\n", T++, ans);
    }
    return 0;
}
