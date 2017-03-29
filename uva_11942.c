#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int a[10],T,i,ans;
    scanf("%hu", &T);
    printf("Lumberjacks:\n");
    while(T>0)
    {
        for(i=0;i<10;i++)
            scanf("%hu", &a[i]);
        if(a[0]<a[1])
            ans=1;
        else if(a[0]>a[1])
            ans=2;
        for(i=2;i<10 && ans!=0;i++)
            if(ans==1 && a[i-1]>a[i])
                ans=0;
            else if(ans==2 && a[i-1]<a[i])
                    ans=0;
        if(ans==0)
            printf("Unordered\n");
        else
            printf("Ordered\n");
        T--;
    }
    return 0;
}
