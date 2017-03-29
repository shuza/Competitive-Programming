#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXNODE 105

using namespace std;

int main()
{
    int m, n, i, j, a, b;
 //   freopen("in.txt", "r", stdin);
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        int degree[MAXNODE] = {0};
        vector<int> relation[MAXNODE];
        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            relation[a].push_back(b);
            degree[b]++;
        }
        queue<int> Q;
        vector<int> orderList;
        for(i = 1; i <= n; i++)
            if(degree[i] == 0)
                Q.push(i);
        while(!Q.empty())
        {
            a = Q.front();
            Q.pop();
            orderList.push_back(a);
            for(j = 0; j < relation[a].size(); j++)
            {
                degree[relation[a][j]]--;
                if(degree[relation[a][j]] == 0)
                    Q.push(relation[a][j]);
            }
        }
        for(i = 0; i < orderList.size(); i++)
            cout << orderList[i] << " ";
        cout << endl;
    }
    return 0;
}