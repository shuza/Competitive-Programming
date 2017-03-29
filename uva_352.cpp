#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXROW 26

int visit[MAXROW][MAXROW], n;
string in[MAXROW];

struct data{
    int r, c;
};

void BFS(int row, int col){
    visit[row][col] = 1;
    data test;
    test.r = row;
    test.c = col;
    queue<data> q;
    q.push(test);
    while(!q.empty()){
        test = q.front();   q.pop();
        row = test.r;
        col = test.c;

        // check up adj
        if(row > 0 && in[row-1][col] == '1' && !visit[row-1][col]){
            visit[row-1][col] = 1;
            test.r = row - 1;
            test.c = col;
            q.push(test);
        }

        // check down adj
        if(row < n-1 && in[row+1][col] == '1' && !visit[row+1][col]){
            visit[row+1][col] = 1;
            test.r = row + 1;
            test.c = col;
            q.push(test);
        }

        // check right adj
        if(col < n-1 && in[row][col+1] == '1' && !visit[row][col+1]){
            visit[row][col+1] = 1;
            test.r = row;
            test.c = col + 1;
            q.push(test);
        }

        // check left adj
        if(col > 0 && in[row][col-1] == '1' && !visit[row][col-1]){
            visit[row][col-1] = 1;
            test.r = row;
            test.c = col - 1;
            q.push(test);
        }

        // check up-left adj
        if(row > 0 && col > 0 && in[row-1][col-1] == '1' && !visit[row-1][col-1]){
            visit[row-1][col-1] = 1;
            test.r = row - 1;
            test.c = col - 1;
            q.push(test);
        }

        // check up-right adj
        if(row > 0 && col < n-1 && in[row-1][col+1] == '1' && !visit[row-1][col+1]){
            visit[row-1][col+1] = 1;
            test.r = row - 1;
            test.c = col + 1;
            q.push(test);
        }

        // check down-left adj
        if(row < n-1 && col > 0 && in[row+1][col-1] == '1' && !visit[row+1][col-1]){
            visit[row+1][col-1] = 1;
            test.r = row + 1;
            test.c = col - 1;
            q.push(test);
        }

        // check down-right adj
        if(row < n-1 && col < n-1 && in[row+1][col+1] == '1' && !visit[row+1][col+1]){
            visit[row+1][col+1] = 1;
            test.r = row + 1;
            test.c = col + 1;
            q.push(test);
        }
    }
}

int main()
{
    int cas = 1;
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> in[i];
        int ans = 0;
        memset(visit, 0, sizeof(visit));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(in[r][c] == '1' && !visit[r][c]){
                    BFS(r, c);
                    ans++;
                }
            }
        }
        cout << "Image number " << cas++ << " contains " << ans << " war eagles." << endl;
    }
    return 0;
}
