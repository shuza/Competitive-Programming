#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MAXN 20000002
#define MAXPRIME 100001

long isPrime[MAXN];
long A[MAXN];

void sieve(){
    long sq = sqrt(MAXN);
    for(long i = 4; i < MAXN; i += 2)
        isPrime[i] = 1;
    for(long i = 3; i < sq; i += 2){
        if(!isPrime[i]){
            for(long j = i*i; j < MAXN; j += i)
                isPrime[j] = 1;
        }
    }
}

int main()
{
    sieve();
    int l = 0;
    for(long i = 3; i < MAXN; i += 2){
        if(!isPrime[i] && !isPrime[i+2]){
            A[l++] = i;
        }
    }
    int n;
    while(cin >> n){
        cout << "(" << A[n-1] << ", " << (A[n-1] + 2) << ")" << endl;
    }
    return 0;
}
