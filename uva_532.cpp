#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define MAXNODE 32

struct data{
    int l, r, c;
};

int main()
{
    freopen("in.txt", "r", stdin);
    int L, R, C;
    while(cin >> L >> R >> C){
        if(!(L || R || C))
            break;
        string s[MAXNODE][MAXNODE];
        int srcL, srcR, srcC, desL, desR, desC;
        bool src, des;
        src = des = false;
        for(int i = 0; i < L; i++)
            for(int j = 0; j < R; j++){
                cin >> s[i][j];
                for(int k = 0; k < C && !(src && des); k++)
                    if(s[i][j][k] == 'S'){
                        srcL = i;
                        srcR = j;
                        srcC = k;
                        src = true;
                    }
                    else if(s[i][j][k] == 'E'){
                        desL = i;
                        desR = j;
                        desC = k;
                        des = true;
                    }
            }
        int visit[MAXNODE][MAXNODE][MAXNODE] = {0};
        data test;
        test.l = srcL;
        test.r = srcR;
        test.c = srcC;
        queue<data> q;
        q.push(test);
        visit[srcL][srcR][srcC] = 1;
        int dl[6] = {0, 0, 0, 0, 1, -1};
        int dr[6] = {0, 0, 1, -1, 0, 0};
        int dc[6] = {1, -1, 0, 0, 0, 0};
        while(!q.empty()){
            if(visit[desL][desR][desC])
                break;
            test = q.front();
            q.pop();
            for(int i = 0; i < 6; i++){
                int l = test.l + dl[i];
                int r = test.r + dr[i];
                int c = test.c + dc[i];
                if((l >= 0 && l < L) && (r >= 0 && r < R) && (c >= 0 && c < C) && !visit[l][r][c] && s[l][r][c] != '#'){
                    data a;
                    a.l = l;
                    a.r = r;
                    a.c = c;
                    q.push(a);
                    visit[l][r][c] = visit[test.l][test.r][test.c] + 1;
                }
            }
        }
        if(visit[desL][desR][desC])
            cout << "Escaped in " << (visit[desL][desR][desC] - 1) << " minute(s)." << endl;
        else
            puts("Trapped!");
    }
    return 0;
}
