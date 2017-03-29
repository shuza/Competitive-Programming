#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a,b,c,t;
    while(scanf("%u %u %u", &a, &b, &c)==3)
    {
        if(a==0 && b==0 && c==0)
            break;
        if(a>b && a>c)
        {
            t=a;
            a=c;
            c=t;
        }
        else if(b>a && b>c)
        {
            t=b;
            b=c;
            c=t;
        }
        b=b*b+a*a;
        c=c*c;
        if(b==c)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}
