#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long a, b;
        scanf("%ld %ld", &a, &b);
        long g = __gcd(a, b);
        long sq = sqrt(g);
        long ans = 0;
        for(long i = 1; i <= sq; i++){
            if(g %i == 0){
                ans++;
                if(i * i != g)
                    ans++;
            }
        }
        printf("%ld\n", ans);
    }
    return 0;
}
