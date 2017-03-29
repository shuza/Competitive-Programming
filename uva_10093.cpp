#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int chartonum(char c)
{
    if(c >= 'A' && c <= 'Z')
        return (c - 55);
    if(c >= 'a' && c <= 'z')
        return (c - 61);
    return (c - '0');
}

int main()
{
    string s;
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    while(cin >> s)
    {
        long long num = 0;
        int i, base = 2;
        i = s.size();
        i--;
        while(i >= 0)
        {
            if(s[i] == '-' || s[i] == '+')
                break;
            num += chartonum(s[i]);
            if(chartonum(s[i]) >= base)
                base = chartonum(s[i]) + 1;
            i--;
        }
        while(base <= 62)
        {
            if(num % (base - 1) == 0)
                break;
            base++;
        }
        if(base <= 62 && num % (base-1) == 0)
            cout << base << endl;
        else
            cout << "such number is impossible!" << endl;
    }
    return 0;
}
