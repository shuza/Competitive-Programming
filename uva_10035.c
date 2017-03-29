#include <stdio.h>

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long int a,b;
    unsigned short int count,carry;
    while(scanf("%ld %ld", &a, &b)==2)
    {
        if( a==0 && b==0 )
            break;
        count=0;
        carry=0;
        while( a!=0 || b!=0 )
        {
            carry=( (a%10) + (b%10) + carry )/10 ;
            a/=10;
            b/=10;
            if(carry!=0)
                count++;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("%hu carry operation.\n", count);
        else
            printf("%hu carry operations.\n", count);
    }
    return 0;
}
