#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int par[27];

void init(int a)
{
    for(int i = 1; i <= a; i++)
        par[i] = i;
}

int getnum(char c)
{
    return (c - 'A' + 1);
}

int getParent(int a)
{
    if(a == par[a])
        return a;
    return par[a] = getParent(par[a]);
}

int main()
{
    int cas, i;
    string s;
    bool blank = false;
    freopen("in.txt", "r", stdin);
    cin >> cas;
    while(cas--)
    {
        int ans, N, a, b;
        char top;
        cin >> top;
        N = getnum(top);
        init(N);
        ans = N;
        cin.ignore();
        while(true)
        {
            getline(cin, s);
            if(s == "")
                break;
            a = getnum(s[0]);
            b = getnum(s[1]);
            a = getParent(a);
            b = getParent(b);
            if(a != b)
            {
                par[a] = b;
                ans--;
            }
        }
        if(blank)
            cout << endl;
        blank = true;
        cout << ans << endl;
    }
    return 0;
}
