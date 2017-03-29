#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double circle, box, r, ans, pi ;
    int T, i ;
    scanf("%d", &T);
    pi=2*acos(0.0);
    for(i=1;i<=T;i++)
    {
        scanf("%lf", &r);
        circle=pi*r*r;
        r*=2;
        box=r*r;
        ans=box-circle+1e-9;
        printf("Case %d: %.2lf\n", i, ans);
    }
    return 0;
}
