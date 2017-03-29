#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int a,b;
    while(scanf("%lu %lu", &a, &b)!=EOF)
    {
        if(a>b)
            a-=b;
        else
            a=b-a;
        printf("%lu\n", a);
    }
    return 0;
}
