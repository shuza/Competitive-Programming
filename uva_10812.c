#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,def,a,b,count;
    scanf("%d", &count);
    while(count>0)
    {
        scanf("%d %d", &sum, &def);
        a=sum+def ;
        b=sum-def ;
        if( a%2!=0 || b%2!=0 || b<0 )
            printf("impossible\n") ;
        else
            printf("%d %d\n", a/2, b/2 ) ;
        count-- ;
    }
    return 0;
}
