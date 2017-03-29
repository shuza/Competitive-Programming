#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
struct data{
    int row, col;
};

#define MAXNODE 1000
int edge[MAXNODE][MAXNODE];

void fun_in(){
    memset(edge, 0, sizeof(edge));
    int n;
    scanf("%d", &n);
    while(n--){
        int row, col, i;
        cin >> row >> i;
        while(i--){
            cin >> col;
            edge[row][col] = 1;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int row, col;
    while(cin >> row >> col){
        if(!(row || col))
            break;
        fun_in();
        int srcR, srcC, desR, desC;
        scanf("%d %d %d %d", &srcR, &srcC, &desR, &desC);
        queue<data> q;
        data test;
        test.row = srcR;
        test.col = srcC;
        q.push(test);
        edge[srcR][srcC] = 1;
        while(!q.empty()){
            if(edge[desR][desC] > 0)
                break;
            data x = q.front();
            q.pop();
            if(x.row > 0 && edge[x.row-1][x.col] == 0){     // check move up
                data y;
                y.row = x.row-1;
                y.col = x.col;
                q.push(y);
                edge[x.row-1][x.col] = edge[x.row][x.col]+1;
            }
            if(x.col > 0 && edge[x.row][x.col-1] == 0){     // check move left
                data y;
                y.row = x.row;
                y.col = x.col-1;
                q.push(y);
                edge[x.row][x.col-1] = edge[x.row][x.col]+1;
            }
            if(x.col < col-1 && edge[x.row][x.col+1] == 0){     // check move right
                data y;
                y.row = x.row;
                y.col = x.col + 1;
                q.push(y);
                edge[x.row][x.col+1] = edge[x.row][x.col]+1;
            }
            if(x.row < row-1 && edge[x.row+1][x.col] == 0){     // check move down
                data y;
                y.row = x.row+1;
                y.col = x.col;
                q.push(y);
                edge[x.row+1][x.col] = edge[x.row][x.col]+1;
            }
        }
        printf("%d\n", edge[desR][desC]-1);
    }
    return 0;
}
