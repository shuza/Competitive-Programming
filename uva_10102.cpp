#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
using namespace std;
#define INF (1<<31)
#define eps (1e-11)
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXROW 500

string in[MAXROW];
int n;

struct node{
    int row, col;
};

int BFS(int r, int c){
    node test;
    test.row = r;
    test.col = c;
    queue<node> q;
    q.push(test);
    int dis[MAXROW][MAXROW] = {0};
    dis[r][c] = 1;
    while(!q.empty()){
        test = q.front();   q.pop();
        r = test.row;
        c = test.col;
        if(in[r][c] == '3')
            return dis[r][c]-1;

            // check up move
        if(r > 0 && !dis[r-1][c]){
            test.row = r-1;
            test.col = c;
            q.push(test);
            dis[r-1][c] = dis[r][c] + 1;
        }

            // check right move
        if(c < n-1 && !dis[r][c+1]){
            test.row = r;
            test.col = c+1;
            q.push(test);
            dis[r][c+1] = dis[r][c] + 1;
        }

            // check down move
        if(r < n-1 && !dis[r+1][c]){
            test.row = r + 1;
            test.col = c;
            q.push(test);
            dis[r+1][c] = dis[r][c] + 1;
        }

            // check left move
        if(c > 0 && !dis[r][c-1]){
            test.row = r;
            test.col = c - 1;
            q.push(test);
            dis[r][c-1] = dis[r][c] + 1;
        }
    }
    return MAXROW;
}

int main()
{

    while(cin >> n){
        getchar();
        for(int i = 0; i < n; i++)
            getline(cin, in[i]);
        int ans = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            if(in[i][j] == '1'){
                ans = max(ans, BFS(i, j));
            }
        cout << ans << endl;
    }
    return 0;
}
