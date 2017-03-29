#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p,T,test,j;
    scanf("%d", &T);
    while(T>0)
    {
        scanf("%d,", &p);
        if( p==2 || p==0 )
            printf("Yes\n");
        else if( p%2==0 )
            printf("No\n");
        else
            {
                test=0;
                for(j=3;j<p;j+=2)
                    if(p%j==0)
                    {
                        test=1;
                        break;
                    }
                if(test==0)
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        T--;
    }

    return 0;
}
