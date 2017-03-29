#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define MAXTARGET 16

int w[MAXTARGET][MAXTARGET], n, health[MAXTARGET];
int dp[(1<<MAXTARGET) + 2];

int setWapen(int N, int pos){ return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N | ~(1 << pos); }
bool checkWapen(int N, int pos){ return (bool) (N & (1 << pos)); }

int fun(int mask){
    if(mask == (1 << n)-1)  return 0;
    if(dp[mask] != -1)  return dp[mask];
    int mn = 1 << 29;
    for(int i = 0; i < n; i++){
        if(!checkWapen(mask, i)){
            int shots = 1;
            for(int j = 0; j < n; j++){
                if(i != j && checkWapen(mask, j)){
                    shots = max(shots, w[j][i]);
                }
            }
            int wap = health[i] / shots;
            if(health[i] % shots != 0){
                wap++;
            }
            wap += fun(setWapen(mask, i));
            mn = min(mn, wap);
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
            cin >> health[i];
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                w[i][j] = s[j] - '0';
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << caseno++ << ": " << fun(0) << endl;
    }
    return 0;
}
