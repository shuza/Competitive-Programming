#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        int n, b, w, tie, a;
        b = w = tie = a = 0;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'B')
                b++;
            else if(s[i] == 'W')
                w++;
            else if(s[i] == 'T')
                tie++;
            else
                a++;
        cout << "Case " << cas++ << ": ";
        if(a == n)
            puts("ABANDONED");
        else if(!w && !tie)
            puts("BANGLAWASH");
        else if(!b && !tie)
            puts("WHITEWASH");
        else if(b > w)
            cout << "BANGLADESH " << b << " - " << w << endl;
        else if(w > b)
            cout << "WWW " << w << " - " << b << endl;
        else
            cout << "DRAW " << b << " " << tie << endl;
    }
    return 0;
}
