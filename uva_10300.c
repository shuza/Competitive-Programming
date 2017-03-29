#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int ans,x,y,z;
    unsigned short int farmer, count, i;
    scanf("%hu", &count);
    while(count>0)
    {
        scanf("%hu", &farmer);
        ans=0;
        for(i=0;i<farmer;i++)
        {
            scanf("%lu %lu %lu", &x, &y, &z);
            ans+=(x*z);
        }
        printf("%lu\n", ans);

        count--;
    }
    return 0;
}
