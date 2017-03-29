#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define INF (1<<30)
#define eps 1e-11
#define MAXC 105

int main()
{
    freopen("in.txt", "r", stdin);
    int n, m, cas = 1;
    bool line = false;
    while(cin >> n >> m){
        if(!(n || m))
            break;
        int ans[MAXC][MAXC] = {0};
        string s[MAXC];
        for(int i = 0; i < n; i++)
            cin >> s[i];
        if(line)
            cout << endl;
        else
            line = true;
        cout << "Field #" << cas++ << ":" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(s[i][j] == '*'){
                    cout << "*";
                    continue;
                }
                int ans = 0;
                if(i > 0){                  // up row check
                    if(s[i-1][j] == '*')
                        ans++;
                    if(j > 0 && s[i-1][j-1] == '*')
                        ans++;
                    if(j < m-1 && s[i-1][j+1] == '*')
                        ans++;
                }
                if(i < n-1){                // down row check
                    if(s[i+1][j] == '*')
                        ans++;
                    if(j > 0 && s[i+1][j-1] == '*')
                        ans++;
                    if(j < m-1 && s[i+1][j+1] == '*')
                        ans++;
                }
                if(j > 0 && s[i][j-1] == '*')       // left check
                    ans++;
                if(j < m-1 && s[i][j+1] == '*')     // right check
                    ans++;
                cout << ans;
            }
            cout << endl;
        }
    }
    return 0;
}
