#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int T,count,N,i,stand,now,high,low;
    scanf("%hu", &T);
    for(count=1;count<=T;count++)
    {
        high=0;
        low=0;
        now=0;
        scanf("%hu", &N);
        for(i=0;i<N;i++)
        {
            scanf("%hu", &stand);
            if(now<stand)
            {
                high++;
                now=stand;
            }
            else if(now>stand)
            {
                low++;
                now=stand;
            }
        }
        printf("Case %hu: %hu %hu\n", count, high-1, low);

    }
    return 0;
}
