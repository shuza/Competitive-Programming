#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#define INF (1<<30)
#define eps (1e-11)
using namespace std;

struct data{
    int row, col;
};

#define MAXLAND 22

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        int row, col, srcR, srcC;
        string str[MAXLAND];
        cin >> col >> row;
        getline(cin, str[MAXLAND-1]);
        for(int i = 0; i < row; i++){
            getline(cin, str[i]);
            for(int j = 0; j < str[i].size(); j++)
                if(str[i][j] == '@'){
                    srcR = i;
                    srcC = j;
                    break;
                }
        }
        int dis[MAXLAND][MAXLAND] = {0};
        int ans = 1;
        data test;
        test.row = srcR;
        test.col = srcC;
        dis[row][col] = 1;
        queue<data>q;
        q.push(test);
        while(!q.empty()){
            test = q.front();
            q.pop();
            if(test.row > 0 && str[test.row-1][test.col] == '.' && dis[test.row-1][test.col] == 0){     // move up
                dis[test.row-1][test.col] = 1;
                data y;
                y.row = test.row-1;
                y.col = test.col;
                q.push(y);
                ans++;
            }
            if(test.row < row-1 && dis[test.row+1][test.col] == 0 && str[test.row+1][test.col] == '.'){     // move down
                dis[test.row+1][test.col] = 1;
                data y;
                y.row = test.row+1;
                y.col = test.col;
                q.push(y);
                ans++;
            }
            if(test.col > 0 && dis[test.row][test.col-1] == 0 && str[test.row][test.col-1] == '.'){     // move left
                dis[test.row][test.col-1] = 1;
                data y;
                y.row = test.row;
                y.col = test.col-1;
                q.push(y);
                ans++;
            }
            if(test.col < col-1 && dis[test.row][test.col+1] == 0 && str[test.row][test.col+1] == '.'){     // move right
                dis[test.row][test.col+1] = 1;
                data y;
                y.row = test.row;
                y.col = test.col+1;
                q.push(y);
                ans++;
            }
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
