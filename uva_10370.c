#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,num[1001],i,count,T;
    double result;
    long int add;
    scanf("%d", &T);
    while(T>0)
    {
        scanf("%d", &N);
        add=0;
        count=0;
        for(i=0;i<N;i++)
        {
            scanf("%d", &num[i]);
            add+=num[i];
        }
        add/=N;
        for(i=0;i<N;i++)
            if(add<num[i])
                count++;
        result=(double)count/N*100;
        printf("%.3lf%\n", result);
        T--;
    }
    return 0;
}
