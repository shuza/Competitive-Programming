    /****
        author: Shalauddin Ahamad Shuza
        algo:   Bitmask DP
    ****/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string in;
int dp[(1<<12)+5];

int Set(int N, int pos){ return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~(1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

int fun(int mask){
    if(!mask)
        return 0;
    if(dp[mask] != -1)
        return 0;
    int ans = 0;
    for(int i = 2; i < 12; i++){
        int a, b;
        a = b = 0;
        if(check(mask, i) && check(mask, i-1) && !check(mask, i-2)){
            int tmask = reset(mask, i);
            tmask = reset(tmask, i-1);
            tmask = Set(tmask, i-2);
            a = 1 + fun(tmask);
        }
        if(i < 11 && check(mask, i-2) && check(mask, i-1) && !check(mask, i)){
            int tmask = reset(mask, i-2);
            tmask = reset(tmask, i-1);
            tmask = Set(tmask, i);
            b = 1 + fun(tmask);
        }
        ans = max(ans, max(a, b));
    }
    return dp[mask] = ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> in;
        int mask = 0;
        for(int i = 0; i < 12; i++){
            if(in[i] == 'o'){
                mask = Set(mask, i);
                ans++;
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << ans - fun(mask) << endl;
    }
    return 0;
}
