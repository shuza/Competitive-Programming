#include <stdio.h>
#include <stdlib.h>

long GCD(long a, long b)
{
    long r;
    while(b % a != 0)
    {
        r = b % a;
        b = a;
        a = r;
    }
    return a;
}

long long nCr(long n, long r)
{
    long long up, down, toMul, toDiv, i, g;
    if(r > n/2)
        r = n - r;
    up = down = 1;
    for(i = r; i; i--)
    {
        toMul = n - r + i;
        toDiv = i;
        g = GCD(toMul, toDiv);
        toMul /= g;
        toDiv /= g;
        g = GCD(toMul, down);
        toMul /= g;
        down /= g;
        g = GCD(toDiv, up);
        toDiv /= g;
        up /= g;
        up = (up*toMul);
        down = (down*toDiv);
    }
    return (up/down);
}

int main()
{
    printf("%d", nCr(4,2));
    return 0;
}
