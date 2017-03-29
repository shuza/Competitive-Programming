#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int flag[1000001]={0};
    unsigned long int input,i,j,a,b;
    flag[1]=1;
    for(i=4;i<1000000;i+=2)
        flag[i]=1;
    for(i=3;i<1000000;i+=2)
        if(flag[i]==0)
            for(j=i*i;j<1000000;j+=i)
                flag[j]=1;
    while(scanf("%lu", &input)==1)
    {
        if(input==0)
            break;
        for(i=2;i<input;i++)
        {
            if(flag[i]==0)
            {
                a=i;
                b=input-i;
            }
            if(flag[a]==0 && flag[b]==0)
                break;
        }
        if(flag[a]==0 && flag[b]==0)
            printf("%lu = %lu + %lu\n", input, a, b);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
