#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int H1,H2,M1,M2;
    int now,alarm,ans;
    while(scanf("%hu %hu %hu %hu", &H1, &M1, &H2, &M2)==4)
    {
        if(H1==0 && H2==0 && M1==0 && M2==0)
            break;
        if(H2<H1)
            H2+=24;
        else if( H1==H2 && M2<M1 )
                H2+=24;
        now=H1*60+M1;
        alarm=H2*60+M2;
        ans=alarm-now;
        printf("%d\n", ans);

    }
    return 0;
}
