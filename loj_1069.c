#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    unsigned int T,i,my,floor;
    int time;
    scanf("%u",&T);
    for(i=1;i<=T;i++)
    {
        time=0;
        scanf("%u %u", &my, &floor);
        if(floor<my)
        {
            floor=my+(my-floor);
        }
        time=floor*4;
        time+=19;
        printf("Case %u: %d\n", i, time);
    }
    return 0;
}
 