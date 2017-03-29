#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <map>
#define MAXNODE 105

using namespace std;

int main()
{
    int N, M, i, cas = 1;
//    freopen("in.txt", "r", stdin);
    while(cin >> N)
    {
        string name[MAXNODE];
        map<string, int>encode;
        for(i = 0; i < N; i++)
        {
            cin >> name[i];
            encode[name[i]] = i;
        }
        vector<int> relation[MAXNODE];
        int degree[MAXNODE] = {0};
        cin >> M;
        for(i = 0; i < M; i++)
        {
            string txt1, txt2;
            cin >> txt1 >> txt2;
            int a = encode[txt1];
            int b = encode[txt2];
            relation[a].push_back(b);
            degree[b]++;
        }
        bool visit[MAXNODE] = {false};
        cout << "Case #" << cas++ << ": Dilbert should drink beverages in this order:";
        for(i = 0; i < N; i++)
        {
            if(!visit[i] && degree[i] == 0)
            {
                cout << " " << name[i];
                visit[i] = true;
                for(int j = 0; j < relation[i].size(); j++)
                    degree[relation[i][j]]--;
                i = -1;
            }
        }
        cout << "." << endl << endl;
    }
    return 0;
}
