#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,y1,y2,xc,yc,T,i,M,j;
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &M );
        printf("Case %d:\n", i);
        for(j=0;j<M;j++)
        {
            scanf("%d%d", &xc, &yc );
            if( xc>x1 && xc<x2 && yc>y1 && yc<y2 )
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
