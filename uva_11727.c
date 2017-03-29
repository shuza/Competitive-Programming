#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a[3],ans;
    unsigned short int T,count,i,j;
    scanf("%hu", &T);
    for(count=1;count<=T;count++)
    {
        scanf("%u %u %u", &a[0], &a[1], &a[2]);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                if(a[i]>a[j])
                {
                    ans=a[i];
                    a[i]=a[j];
                    a[j]=ans;
                }
        printf("Case %hu: %u\n", count, a[1]);

    }
    return 0;
}
