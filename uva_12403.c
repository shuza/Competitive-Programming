#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10];
    int T;
    unsigned int K;
    unsigned long int ans=0;
    scanf("%d", &T);
    while(T>0)
    {
        scanf("%s", input);
        if(input[0]=='d')
        {
            scanf("%u", &K);
            ans+=K;
        }
        else
            printf("%lu\n", ans);
        T--;
    }
    return 0;
}
