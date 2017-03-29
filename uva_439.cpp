#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define INF (1<<30)
#define eps (1e-11)
using namespace std;

#define MAXNODE 9

struct data{
    int r, c;
};

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2){
        int srcR, srcC, desR, desC;
        srcC = (int) s1[0] - 'a' + 1;
        srcR = (int) s1[1] - '0';
        desC = (int) s2[0] - 'a' + 1;
        desR = (int) s2[1] - '0';
        int table[MAXNODE][MAXNODE] = {0};
        table[srcR][srcC] = 1;
        queue<data> q;
        data test;
        test.r = srcR;
        test.c = srcC;
        q.push(test);
        while(!q.empty()){
            if(table[desR][desC])
                break;
            test = q.front();
            q.pop();
            if(test.c < 7){         //  check 2right move
                if(test.r < 8 && table[test.r+1][test.c+2] == 0){
                    data x;
                    x.r = test.r + 1;
                    x.c = test.c + 2;
                    q.push(x);
                    table[test.r+1][test.c+2] = table[test.r][test.c] + 1;
                }
                if(test.r > 1 && table[test.r-1][test.c+2] == 0){
                    data x;
                    x.r = test.r - 1;
                    x.c = test.c + 2;
                    q.push(x);
                    table[test.r-1][test.c+2] = table[test.r][test.c] + 1;
                }
            }
            if(test.c < 8){         // check 1right move
                if(test.r < 7 && table[test.r+2][test.c+1] == 0){
                    data x;
                    x.r = test.r + 2;
                    x.c = test.c + 1;
                    q.push(x);
                    table[test.r+2][test.c+1] = table[test.r][test.c] + 1;
                }
                if(test.r > 2 && table[test.r-2][test.c+1] == 0){
                    data x;
                    x.r = test.r - 2;
                    x.c = test.c + 1;
                    q.push(x);
                    table[test.r-2][test.c+1] = table[test.r][test.c] + 1;
                }
            }
            if(test.c > 2){     // check 2left move
                if(test.r < 8 && table[test.r+1][test.c-2] == 0){
                    data x;
                    x.r = test.r + 1;
                    x.c = test.c - 2;
                    q.push(x);
                    table[test.r+1][test.c-2] = table[test.r][test.c] + 1;
                }
                if(test.r > 1 && table[test.r-1][test.c-2] == 0){
                    data x;
                    x.r = test.r - 1;
                    x.c = test.c - 2;
                    q.push(x);
                    table[test.r-1][test.c-2] = table[test.r][test.c] + 1;
                }
            }
            if(test.c > 1){         // check 1left move
                if(test.r < 7 && table[test.r+2][test.c-1] == 0){
                    data x;
                    x.r = test.r + 2;
                    x.c = test.c - 1;
                    q.push(x);
                    table[test.r+2][test.c-1] = table[test.r][test.c] + 1;
                }
                if(test.r > 2 && table[test.r-2][test.c-1] == 0){
                    data x;
                    x.r = test.r - 2;
                    x.c = test.c - 1;
                    q.push(x);
                    table[test.r-2][test.c-1] = table[test.r][test.c] + 1;
                }
            }
        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << table[desR][desC]-1 << " knight moves." << endl;
    }
    return 0;
}
