#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int convNum(string str)
{
    int ans = 0;
    for(int i = 0; i < str.size(); i++)
        ans = ans*10 + (str[i]-'0');
    return ans;
}

int main()
{
    char str[100];
    char op;
    int a, b, c, ans = 0;
    while(scanf("%d%c%d=%s", &a, &op, &b, str) != EOF)
    {
        if(str[0] == '?')
            continue;
        c = convNum(str);
        if(op == '+' && c == a + b)
            ans++;
        else if(c == a-b)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
