#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXROW 102

string in[MAXROW];
int visit[MAXROW][MAXROW], row, col;

struct data{
    int u, v;
};

void BFS(int r, int c){
    visit[r][c] = 1;
    data test;
    test.u = r;
    test.v = c;
    queue<data> q;
    q.push(test);
    while(!q.empty()){
        test = q.front();   q.pop();
        r = test.u;
        c = test.v;

        // check up adj
        if(r > 0 && in[r-1][c] == '@' && !visit[r-1][c]){
            visit[r-1][c] = 1;
            test.u = r - 1;
            test.v = c;
            q.push(test);
        }

        // check down adj
        if(r < row-1 && in[r+1][c] == '@' && !visit[r+1][c]){
            visit[r+1][c] = 1;
            test.u = r + 1;
            test.v = c;
            q.push(test);
        }

        // check left adj
        if(c > 0 && in[r][c-1] == '@' && !visit[r][c-1]){
            visit[r][c-1] = 1;
            test.u = r;
            test.v = c - 1;
            q.push(test);
        }

        // check right adj
        if(c < col-1 && in[r][c+1] == '@' && !visit[r][c+1]){
            visit[r][c+1] = 1;
            test.u = r;
            test.v = c + 1;
            q.push(test);
        }

        // check up-left adj
        if(r > 0 && c > 0 && in[r-1][c-1] == '@' && !visit[r-1][c-1]){
            visit[r-1][c-1] = 1;
            test.u = r - 1;
            test.v = c - 1;
            q.push(test);
        }

        // check up-right adj
        if(r > 0 && c < col-1 && in[r-1][c+1] == '@' && !visit[r-1][c+1]){
            visit[r-1][c+1] = 1;
            test.u = r - 1;
            test.v = c + 1;
            q.push(test);
        }

        // check down-left adj
        if(r < row-1 && c > 0 && in[r+1][c-1] == '@' && !visit[r+1][c-1]){
            visit[r+1][c-1] = 1;
            test.u = r + 1;
            test.v = c - 1;
            q.push(test);
        }

        // check down-right adj
        if(r < row-1 && c < col-1 && in[r+1][c+1] == '@' && !visit[r+1][c+1]){
            visit[r+1][c+1] = 1;
            test.u = r + 1;
            test.v = c + 1;
            q.push(test);
        }
    }
}

int main()
{
    while(cin >> row >> col){
        if(!row && !col)
            break;
        for(int i = 0; i < row; i++)
            cin >> in[i];
        memset(visit, 0, sizeof(visit));
        int ans = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(in[i][j] == '@' && !visit[i][j]){
                    BFS(i, j);
                    ans++;
                }
        cout << ans << endl;
    }
    return 0;
}
