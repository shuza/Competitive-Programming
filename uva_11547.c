#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int t,count;
    int n;
    long int ans;
    scanf("%hu", &t);
    for(count=1;count<=t;count++)
    {
        scanf("%d", &n);
        ans=315*n+36962;
        ans%=100;
        n=ans/10;
        if(n<0)
            n*=-1;
        printf("%d\n", n);
    }
    return 0;
}
