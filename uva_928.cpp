#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 303

string in[MAXNODE];
int row, col;

struct data{
    int r, c, dis, mv;
};

int BFS(int r, int c){
    int visit[MAXNODE][MAXNODE][4] = {0};
    int dr[] = {1, 0, -1, 0};
    int dc[] = {0, 1, 0, -1};
    visit[r][c][0] = 1;
    data test;
    test.r = r;
    test.c = c;
    test.dis = 0;
    test.mv = 0;
    queue<data> q;
    q.push(test);
    while(!q.empty()){
        test = q.front();   q.pop();
        r = test.r;     c = test.c;
        int d = test.dis, m = test.mv;
        if(in[r][c] == 'E')
            return test.dis;
        for(int i = 0; i < 4; i++){
            int x, y, j;
            x = r;  y = c;
            for(j = m % 3; j >= 0; j--){
                x += dr[i];
                y += dc[i];
                if(x < 0 || y < 0 || x == row || y == col || in[x][y] == '#')
                    break;
            }
            if(j < 0 && !visit[x][y][(m+1)%3]){
                visit[x][y][(m+1)%3] = 1;
                test.r = x;
                test.c = y;
                test.dis = d + 1;
                test.mv = (m+1) % 3;
                q.push(test);
            }
        }
    }
    return -1;
}

int main()
{
    freopen("in.txt", "r", stdin);

    int t;
    cin >> t;
    while(t--){
        int Sr = -1, Sc;
        cin >> row >> col;
        for(int i = 0; i < row; i++){
            cin >> in[i];
            for(int j = 0; j < col && Sr == -1; j++)
                if(in[i][j] == 'S'){
                    Sr = i;
                    Sc = j;
                }
        }
        int ans = BFS(Sr, Sc);
        if(ans == -1)
            puts("NO");
        else
            cout << ans << endl;
    }
    return 0;
}
