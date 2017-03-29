#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)

#define MAXN 105

int dp[MAXN][MAXN], tiles_1[MAXN], tiles_2[MAXN], N1, N2;

int calLCS(int i, int j){
    if(i == N1 || j == N2)  return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    int ans = 0;
    if(tiles_1[i] == tiles_2[j])
        ans = 1 + calLCS(i+1, j+1);
    else
        ans = max(calLCS(i+1, j), calLCS(i, j+1));
    return dp[i][j] = ans;
}

int main()
{
    int caseno = 1;
    while(cin >> N1 >> N2){
        if(!N1 || !N2)  break;
        for(int i = 0; i < N1; i++)
            cin >> tiles_1[i];
        for(int i = 0; i < N2; i++)
            cin >> tiles_2[i];
        memset(dp, -1, sizeof(dp));
        cout << "Twin Towers #" << caseno++ << endl << "Number of Tiles : " << calLCS(0, 0) << endl << endl;
    }
    return 0;
}
