#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 83

string in[MAXNODE];
int n;

struct data{
    int row, col;
};

bool BFS(int r, int c, char match){
    int visit[MAXNODE][MAXNODE] = {0};
    data test;
    test.row = r;
    test.col = c;
    queue<data> q;
    q.push(test);
    visit[r][c] = 1;
    while(!q.empty()){
        test = q.front();   q.pop();
        r = test.row;   c = test.col;
        if(match == 'W' && c == n-1)
            return true;
        if(match == 'B' && r == n-1)
            return true;

        // check up adj
        if(r > 0 && in[r-1][c] == match && !visit[r-1][c]){
            test.row = r - 1;
            test.col = c;
            q.push(test);
            visit[r-1][c] = 1;
        }

        // check down adj
        if(r < n-1 && in[r+1][c] == match && !visit[r+1][c]){
            test.row = r + 1;
            test.col = c;
            q.push(test);
            visit[r+1][c] = 1;
        }

        // check left adj
        if(c > 0 && in[r][c-1] == match && !visit[r][c-1]){
            test.row = r;
            test.col = c - 1;
            q.push(test);
            visit[r][c-1] = 1;
        }

        //check right adj
        if(c < n-1 && in[r][c+1] == match && !visit[r][c+1]){
            test.row = r;
            test.col = c + 1;
            q.push(test);
            visit[r][c+1] = 1;
        }
    }
    return false;
}

bool BFS_fill(int r, int c, char match){
    int visit[MAXNODE][MAXNODE] = {0};
    data test;
    test.row = r;
    test.col = c;
    queue<data> q;
    q.push(test);
    visit[r][c] = 1;
    while(!q.empty()){
        test = q.front();   q.pop();
        r = test.row;   c = test.col;
        if(match == 'W' && c == n-1)
            return true;
        if(match == 'B' && r == n-1)
            return true;

        // check up adj
        if(r > 0 && (in[r-1][c] == match || in[r-1][c] == 'U') && !visit[r-1][c]){
            test.row = r - 1;
            test.col = c;
            q.push(test);
            visit[r-1][c] = 1;
        }

        // check down adj
        if(r < n-1 && (in[r+1][c] == match || in[r+1][c] == 'U') && !visit[r+1][c]){
            test.row = r + 1;
            test.col = c;
            q.push(test);
            visit[r+1][c] = 1;
        }

        // check left adj
        if(c > 0 && (in[r][c-1] == match || in[r][c-1] == 'U') && !visit[r][c-1]){
            test.row = r;
            test.col = c - 1;
            q.push(test);
            visit[r][c-1] = 1;
        }

        //check right adj
        if(c < n-1 && (in[r][c+1] == match || in[r][c+1] == 'U') && !visit[r][c+1]){
            test.row = r;
            test.col = c + 1;
            q.push(test);
            visit[r][c+1] = 1;
        }
    }
    return false;
}

int main()
{
    while(cin >> n){
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> in[i];
        bool ans = false;

        // check white win???
        for(int i = 0; i < n && !ans; i++){
            if(in[i][0] == 'W')
                ans = BFS(i, 0, 'W');
        }
        if(ans){
            puts("White has a winning path.");
            continue;
        }

        // check black win???
        for(int i = 0; i < n && !ans; i++){
            if(in[0][i] == 'B')
                ans = BFS(0, i, 'B');
        }
        if(ans){
            puts("Black has a winning path.");
            continue;
        }

        // check white one move win???
        for(int i = 0; i < n && !ans; i++){
            if(in[i][0] == 'W')
                ans = BFS_fill(i, 0, 'W');
        }
        if(ans){
            puts("White can win in one move.");
            continue;
        }

        // check black one move win???
        for(int i = 0; i < n && !ans; i++){
            if(in[0][i] == 'B')
                ans = BFS_fill(0, i, 'B');
        }
        if(ans)
            puts("Black can win in one move.");
        else
            puts("There is no winning path.");
    }
    return 0;
}
