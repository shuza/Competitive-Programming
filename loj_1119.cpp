    /****
        author: Shalauddin Ahamad Shuza
        algo:   bitmask DP
    ****/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 15

int w[MAXN][MAXN];
int n;
int dp[(1<<MAXN)+2];

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int fun(int mask){
    if(mask == (1<<n) - 1)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];
    int mn = 1 << 28;
    for(int i = 0; i < n; i++){
        if(check(mask, i) == 0){
            int price = w[i][i];
            for(int j = 0; j < n; j++){
                if(i != j && check(mask, j)){
                    price += w[i][j];
                }
            }
            int ret = price + fun(Set(mask, i));
            mn = min(mn, ret);
        }
    }
    return dp[mask] = mn;
}

int main()
{
    int t, caseno = 1;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> w[i][j];
        memset(dp, -1, sizeof(dp));
        int ans = fun(0);
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
    return 0;
}
