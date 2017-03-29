 #include <iostream>
#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int par[200002], sum[200002];

void setParent(int n)
{
    for(int i = 1; i <= 2*n; i++)
    {
        par[i] = i;
        sum[i] = 1;
    }
}

int getParent(int a)
{
    if(a == par[a])
        return a;
    return par[a] = getParent(par[a]);
}

int main()
{
    int cas;
//    freopen("in.txt", "r", stdin);
    cin >> cas;
    while(cas--)
    {
        int N;
        cin >> N;
        int top = 1, i;
        setParent(N);
        map<string, int>encode;
        while(N--)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int a, b;
            if(!encode[s1])
            {
                a = top++;
                encode[s1] = a;
            }
            else
                a = encode[s1];
            if(!encode[s2])
            {
                b = top++;
                encode[s2] = b;
            }
            else
                b = encode[s2];
            a = getParent(a);
            b = getParent(b);
            if(a != b)
            {
                sum[a] += sum[b];
                par[b] = a;
            }
            cout << sum[a] << endl;
        }
    }
    return 0;
}
