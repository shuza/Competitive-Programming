/*
	Author       :	Shuza
	Problem Name :  LOJ - 1200
	Algorithm    :  DP
	Complexity   :
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
#define MAXITEM 101
#define MAXW 10002
int p[MAXITEM], w[MAXITEM], n, cap;
long dp[MAXITEM][MAXW];

long solve(int i, int w_now){
    if(i == n)
        return 0;
    if(dp[i][w_now] != -1)
        return dp[i][w_now];
    int p1 = 0;
    if(w_now + w[i] <= cap)
        p1 = p[i] + solve(i, w_now + w[i]);
    int p2 = solve(i+1, w_now);
    dp[i][w_now] = max(p1, p2);
    return dp[i][w_now];
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        cin >> n >> cap;
        for(int i = 0; i < n; i++){
            int x;
            cin >> p[i] >> x >> w[i];
            cap -= x * w[i];
        }
        cout << "Case " << cas++ << ": ";
        if(cap < 0)
            puts("Impossible");
        else{
            memset(dp, -1, sizeof(dp));
            cout << solve(0, 0) << endl;
        }
    }
    return 0;
}
