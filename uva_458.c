#include <stdio.h>

int main()
{
    char c;
    freopen("input.txt","r",stdin);
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
           printf("\n");
        else
           printf("%c",c-7);
    }
    return 0;
}
