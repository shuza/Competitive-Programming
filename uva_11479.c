#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int T,count=1;
    long int a,b,c;
    scanf("%hu", &T);
    while(count<=T)
    {
        scanf("%ld %ld %ld", &a, &b, &c);
        if(a+b>c && b+c>a && c+a>b)
        {
            if(a==b && b==c)
                printf("Case %hu: Equilateral\n", count);
            else if(a==b || b==c || c==a)
                printf("Case %hu: Isosceles\n", count);
            else
                printf("Case %hu: Scalene\n", count);
        }
        else
            printf("Case %hu: Invalid\n", count);
        count++;
    }
    return 0;
}
