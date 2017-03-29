#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[31];
    int l,a,m;
    long int ans;
    while(scanf("%s", input))
    {
        if(input[0]=='0')
            break;
        l=strlen(input);
        l--;
        ans=0;
        m=1;
        while(l>=0)
        {
            a=(int)input[l] - 48;
            a=a*(pow(2,m)-1);
            ans+=a;
            l--;
            m++;
        }
        printf("%ld\n", ans);
    }
    return 0;
}
