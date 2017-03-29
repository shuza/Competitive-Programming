#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    long long a;
    long b;
    string str;
    int T, cas = 1, i;
    cin >> T;
    while(T--)
    {
        cin >> str >> b;
        int l = str.length();
        b = abs(b);
        a = 0;
        i = 0;
        if(str[i] == '-')
            i++;
        while(i < l)
        {
            a = a * 10 + (str[i] - '0');
            a = a % b;
            i++;
        }
        cout << "Case " << cas++ << ": ";
        if(a == 0)
            cout << "divisible" << endl;
        else
            cout << "not divisible" << endl;
    }
    return 0;
}
