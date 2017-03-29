#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1000002

int isPrime[MAXN];
vector<long>prime;

void sieve(){
    memset(isPrime, 0, sizeof(isPrime));
    for(long i = 4; i < MAXN; i += 2)
        isPrime[i] = 1;
    for(long i = 3; i * i < MAXN; i += 2){
        if(!isPrime[i]){
            for(long j = i*i; j < MAXN; j += i){
                isPrime[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for(long i = 3; i < MAXN; i += 2){
        if(!isPrime[i]){
            prime.push_back(i);
        }
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < prime.size() && prime[i] <= n; i++){
            int c = 0;
            while(n % prime[i] == 0)
                n /= prime[i], c++;
            ans = max(ans, c);
        }
        if(n > 1 && ans < 1)
            ans = 1;
        cout << ans << endl;
    }
    return 0;
}
