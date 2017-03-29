#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
    string s, t;
    while(cin >> s >> t){
        int i, j = 0;
        for(i = 0; i < s.size() && j < t.size(); i++){
            while(s[i] != t[j] && j < t.size())
                j++;
            if(j == t.size())
                break;
            else if(s[i] == t[j])
                j++;
        }
        if(i == s.size())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
