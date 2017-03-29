#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int N, diagonal, lob, hor, index;
    while(scanf("%ld", &N) != EOF)
    {
        index = N;
        for(diagonal = 1; index > diagonal; diagonal++)
            index -= diagonal;
        lob = diagonal % 2 == 0 ? index : diagonal - index + 1;
        hor = diagonal - lob + 1;
        printf("TERM %ld IS %ld/%ld\n", N, lob, hor);
    }
    return 0;
}
