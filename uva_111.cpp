#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)

#define MAXN 22

int dp[MAXN][MAXN], event[MAXN], order[MAXN], N;

int calLCS(int i, int j){
    if(i == N || j == N)  return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    int ans = 0;
    if(event[i] == order[j])
        ans = 1 + calLCS(i+1, j+1);
    else{
        int v1 = calLCS(i+1, j);
        int v2 = calLCS(i, j+1);
        ans = max(v1, v2);
    }
    return dp[i][j] = ans;
}
int main()
{
    cin >> N;
    int x;
    for(int i = 0; i < N; i++){
        cin >> x;
        event[x-1] = i + 1;
    }
        //cin >> event[i];
    while(cin >> x){
        order[x-1] = 1;
        for(int i = 1; i < N; i++){
            cin >> x;
            order[x-1] = i+1;
        }
            //cin >> order[i];
        memset(dp, -1, sizeof(dp));
        cout << calLCS(0, 0) << endl;
    }
    return 0;
}
