#include <stdio.h>
#include <stdlib.h>
#define LLU unsigned long long int

LLU fun(LLU B, LLU P, LLU M)
{
    if(P == 1)
        return (B%M);
    if(P == 0)
        return 1;
    if(P == 2)
        return((B%M)*(B%M))%M;
    LLU test = fun(B, P/2, M);
    test = ((test%M)*(test%M))%M;
    if(P%2 != 0)
        test = (test*B)%M;
    return test;
}

int main()
{
    LLU B,P,M,ans;

    while(scanf("%llu %llu %llu", &B, &P, &M)==3)
    {
        ans = fun(B, P, M);
        printf("%llu\n", ans);
    }
    return 0;
}
