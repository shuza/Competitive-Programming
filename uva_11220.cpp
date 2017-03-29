#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int t, cas = 1;
    bool line = false;
    cin >> t;
    string s;
    getline(cin, s);
    getline(cin, s);
    while(t--){
        if(line)
            puts("");
        cout << "Case #" << cas++ << ":" << endl;
        while(getline(cin, s)){
            if(s == "")
                break;
            string msg = "";
            int i = 0;
            while(i < s.size()){
                while(isspace(s[i]))
                    i++;
                int j = i;
                while(j < s.size() && isalpha(s[j]))
                    j++;
                if(j - i > msg.size()){
                    msg += s[i + msg.size()];
                }
                i = j;
            }
            cout << msg << endl;
        }
        line = true;
    }
    return 0;
}
