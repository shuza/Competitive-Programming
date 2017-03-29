#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

vector<int> V[1002];
int dp[1002][5], parent[1002], visit[1002];

int fun(int state, int isExit)
{
    if(V[state].size() == 0)
        return isExit;
    if(dp[state][isExit] != -1)
        return dp[state][isExit];
    int sum = 0;
    visit[state] = 1;
    for(int i = 0; i < V[state].size(); i++)
    {
        int x = V[state][i];
        if(x != parent[state] && visit[x] != 1)
        {
            parent[x] = state;
            if(isExit == 0)
                sum += fun(x, 1);
            else
                sum += min(fun(x, 1), fun(x, 0));
        }
    }
    visit[state] = 0;
    return dp[state][isExit] = sum + isExit;
}


void reset(){
    for(int i = 0; i < 1002; i++)
        V[i].clear();
}

int main()
{
    int N, i, j, test, adj;
    while(cin >> N)
    {
        if(N == 0)
            break;
        reset();
        for(i = 1; i <= N; i++)
        {
            cin >> j;
            while(j-- > 0)
            {
                cin >>  test;
                V[i].push_back(test);
            }
//            sort(V[i].begin(), V[i].end());
        }
        memset(dp, -1, sizeof(dp));
        memset(visit, 0, sizeof(visit));
        memset(parent, -1, sizeof(parent));
        test = fun(1, 1);
        if(N > 1)
            test = min(test, fun(1, 0));
        cout << test << endl;
    }
    return 0;
}
