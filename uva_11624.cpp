#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define MAXNDOE 1001

int visit[MAXNDOE][MAXNDOE];

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s[MAXNDOE];
        memset(visit, 0, sizeof(visit));
        int R, C, srcR, srcC;
        cin >> R >> C;
        bool loop1, loop2;
        vector<int> r, c, fireR, fireC;
        for(int i = 0; i < R; i++){
            cin >> s[i];
            for(int j = 0; j < s[i].size(); j++)
                if(s[i][j] == 'J'){
                    r.push_back(i);
                    c.push_back(j);
                }
                else if(s[i][j] == 'F'){
                    fireR.push_back(i);
                    fireC.push_back(j);
                }
        }
        long ans = 0;
        bool pass = false;
        while(!r.empty()){
            vector<int>r1, c1;
            for(int i = 0; i < fireR.size(); i++){
                int row = fireR[i], col = fireC[i];
                if(row+1 < R && s[row+1][col] != '#' && visit[row+1][col] != -1){
                    visit[row+1][col] = -1;
                    r1.push_back(row+1);
                    c1.push_back(col);
                }
                if(row > 0 && s[row-1][col] != '#' && visit[row-1][col] != -1){
                    visit[row-1][col] = -1;
                    r1.push_back(row-1);
                    c1.push_back(col);
                }
                if(col+1 < C && s[row][col+1] != '#' && visit[row][col+1] != -1){
                    visit[row][col+1] = -1;
                    r1.push_back(row);
                    c1.push_back(col+1);
                }
                if(col > 0 && s[row][col-1] != '#' && visit[row][col-1] != -1){
                    visit[row][col-1] = -1;
                    r1.push_back(row);
                    c1.push_back(col-1);
                }
            }
            fireR = r1;
            fireC = c1;
            r1.clear();
            c1.clear();
            ans++;
            for(int i = 0; i < r.size(); i++){
                int row = r[i], col = c[i];
                if(row+1 == R || row == 0 || col+1 == C || col == 0){
                    r1.clear();
                    c1.clear();
                    pass = true;
                    break;
                }
                if(row+1 < R && !visit[row+1][col] && s[row+1][col] == '.'){
                    visit[row+1][col] = 1;
                    r1.push_back(row+1);
                    c1.push_back(col);
                }
                if(row > 0 && !visit[row-1][col] && s[row-1][col] == '.'){
                    visit[row-1][col] = 1;
                    r1.push_back(row-1);
                    c1.push_back(col);
                }
                if(col+1 < C && !visit[row][col+1] && s[row][col+1] == '.'){
                    visit[row][col+1] = 1;
                    r1.push_back(row);
                    c1.push_back(col+1);
                }
                if(col > 0 && !visit[row][col-1] && s[row][col-1] == '.'){
                    visit[row][col-1] = 1;
                    r1.push_back(row);
                    c1.push_back(col-1);
                }
            }
            r = r1;
            c = c1;
        }
        if(pass)
            cout << ans << endl;
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}
