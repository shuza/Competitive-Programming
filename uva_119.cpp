#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>
#define MAXNODE 11

using namespace std;

int main()
{
    int N;
    bool line = false;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> N)
    {
        string name[MAXNODE];
        map<string, int>M;
        int has[MAXNODE] = {0};
        int remain[MAXNODE] = {0};
        int recive[MAXNODE] = {0};
        for(int i = 0; i < N; i++)
        {
            cin >> name[i];
            M[name[i]] = i;
        }
        for(int i = 0; i < N; i++)
        {
            string test;
            int j, num, a;
            cin >> test;
            num = M[test];
            cin >> a >> j;
            has[num] += a;
            int num1;
            if(j)
            {
                recive[num] += a % j;
                num1 = a / j;
            }
            else
                recive[num] += a;
            while(j--)
            {
                cin >> test;
                recive[M[test]] += num1;
            }
        }
        if(line)
            cout << endl;
        else
            line = true;
        for(int i = 0; i < N; i++)
        {
            int ans = recive[i] - has[i];
            cout << name[i] << " " << ans << endl;
        }
    }
    return 0;
}
