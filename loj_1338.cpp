#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

int main()
{
    int t, cas = 1;
    cin >> t;
    getchar();
    while(t--){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        int a[27] = {0};
        int b[27] = {0};
        for(int i = 0; i < s1.size() || i < s2.size(); i++){
            if(i < s1.size() && isalpha(s1[i])){
                int x = tolower(s1[i]) - 'a';
                a[x]++;
            }
            if(i < s2.size() && isalpha(s2[i])){
                int x = tolower(s2[i]) - 'a';
                b[x]++;
            }
        }
        bool match = true;
        for(int i = 0; i < 27; i++)
            if(a[i] != b[i]){
                match = false;
                break;
            }
        cout << "Case " << cas++ << ": ";
        if(match)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
