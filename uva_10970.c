    /******     Big  chocklet    ********/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M,N,ans;
    while(scanf("%d %d", &M, &N)!=EOF)
    {
        ans=M*N-1;
        printf("%d\n", ans);
    }
    return 0;
}
