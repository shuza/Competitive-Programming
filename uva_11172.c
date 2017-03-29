#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int a,b;
    unsigned short int t;
    scanf("%hu", &t);
    while(t>0)
    {
        scanf("%ld %ld", &a, &b);
        if(a<b)
            printf("<\n");
        else if(a>b)
            printf(">\n");
        else
            printf("=\n");
        t--;
    }
    return 0;
}
