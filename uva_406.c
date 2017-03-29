#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int flag[1001]={0},i,j,N,C,count,ans[1001],mid;
    while(scanf("%u %u", &N, &C)==2)
    {
        ans[1]=1;
        ans[2]=2;
        if(N==1)
            count=1;
        else
            count=2;
        for(i=4;i<=N;i+=2)
            flag[i]=1;
        for(i=3;i<=N;i+=2)
            if(flag[i]==0)
            {
                ans[++count]=i;
                for(j=i*i;j<=N;j+=i)
                    flag[j]=1;
            }
        if(N==C || count<C*2)
        {
            i=1;
            j=count;
        }
        else if(count%2==0)
            {
                mid=count/2;
                i=mid-C+1;
                j=mid+C;
            }
        else
            {
                mid=(count+1)/2;
                i=mid-C+1;
                j=mid+C-1;
            }
        printf("%u %u:", N, C);
        while(i<=j)
            printf(" %u", ans[i++]);
        printf("\n\n");
    }
    return 0;
}
