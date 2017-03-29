#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int amp,i,j,k;
    unsigned int frn,T,count;
    scanf("%d", &T);
    count=1;
    while(count<=T)
    {
        scanf("%hu %u", &amp, &frn);
        for(i=1;i<=frn;i++)
        {
            for(j=1;j<=amp;j++)
            {
                for(k=1;k<=j;k++)
                    printf("%hu", j);
                printf("\n");
            }
            for(j=amp-1;j>=1;j--)
            {
                for(k=1;k<=j;k++)
                    printf("%hu", j);
                printf("\n");
            }
            if(i!=frn)
               printf("\n");
        }
        if(count!=T)
            printf("\n");
        count++;
    }
    return 0;
}
