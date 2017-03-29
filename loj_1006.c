#include <stdio.h>
#include <stdlib.h>

int a, b, c, d, e, f;

long dp[10002];

int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n] != -1)
        return dp[n];
    dp[n] = (fn(n-1)%10000007 + fn(n-2)%10000007 + fn(n-3)%10000007 + fn(n-4)%10000007 + fn(n-5)%10000007 + fn(n-6)%10000007)%10000007;
    return dp[n];
}

int main() {
    int n, cas = 1, T;
//    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %ld\n", cas++, fn(n) % 10000007);
    }
    return 0;
}
