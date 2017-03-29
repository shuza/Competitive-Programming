#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

int main()
{
    string s;
    while(cin >> s){
        if(s[0] == '#')
            break;
        string a[2];
        a[0] = s;
        next_permutation(s.begin(), s.end());
        a[1] = s;
        s = a[0];
        sort(a, a+2);
        if(a[0] == s && a[0] != a[1])
            cout << a[1] << endl;
        else
            puts("No Successor");
    }
    return 0;
}
