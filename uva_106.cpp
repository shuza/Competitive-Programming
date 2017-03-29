#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
#define MAXN 1000002

short mask[MAXN];

bool coprime(long a, long b){
    long r;
    while(b % a != 0){
        r = b % a;
        b = a;
        a = r;
    }
    if(a > 1)
        return false;
    return true;
}

int main()
{
    long n;
    while(cin >> n){
        long triple = 0, total = 0;
        memset(mask, 0, sizeof(mask));
        long sq = (long) sqrt(n);
        if(sq*sq < n)
            sq++;
        for(long i = 1; i <= sq; i++){
            for(long j = 1; j < i; j++){
                long a, b, c;
                a = i*i - j*j;
                b = 2*i*j;
                c = j*j + i*i;
                if(a*a + b*b == c*c && c <= n && coprime(a, b)){
                    triple++;
                    for(long k = 1; k*c <= n; k++)
                        mask[k*a] = mask[k*b] = mask[k*c] = 1;
                }
            }
        }
        for(long i = 1; i <= n; i++)
            if(!mask[i])
                total++;
        cout << triple << " " << total << endl;
    }
    return 0;
}
