#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ans ;
    long int l, i;
    char in[1000000], t[1000000] ;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while( gets( in ) )
    {
        ans=0 ;
        l = strlen(in);
        for(i = 0; i < l; i++)
        {
            if(in[i] >= 'A' && in[i] <= 'z')
            {
                while(in[i] >= 'A' && in[i] <= 'z')
                    i++;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
