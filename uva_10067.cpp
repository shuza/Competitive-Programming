#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<int> src;
        for(int i = 0; i < 4; i++){
            int a;
            cin >> a;
            src.push_back(a);
        }
        vector<int> des;
        for(int i = 0; i < 4; i++){
            int a;
            cin >> a;
            des.push_back(a);
        }
        int visit[11][11][11][11] = {0};
        visit[src[0]][src[1]][src[2]][src[3]] = 1;
        queue< vector<int> > q;
        q.push(src);
        int n;
        cin >> n;
        while(n--){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            visit[a][b][c][d] = 1;
        }
        bool ans = false;
        while(!q.empty()){
            if(visit[des[0]][des[1]][des[2]][des[3]]){
                ans = true;
                break;
            }
            vector<int> v = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                vector<int> child;
                child = v;
                child[i]++;
                child[i] %= 10;
                if(visit[child[0]][child[1]][child[2]][child[3]] == 0){
                    q.push(child);
                    visit[child[0]][child[1]][child[2]][child[3]] = visit[v[0]][v[1]][v[2]][v[3]] + 1;
                }
            }
            for(int i = 0; i < 4; i++){
                vector<int> child;
                child = v;
                if(child[i] == 0)
                    child[i] = 10;
                child[i]--;
                if(visit[child[0]][child[1]][child[2]][child[3]] == 0){
                    q.push(child);
                    visit[child[0]][child[1]][child[2]][child[3]] = visit[v[0]][v[1]][v[2]][v[3]] + 1;
                }
            }
        }
        if(ans)
            cout << visit[des[0]][des[1]][des[2]][des[3]] - 1 << endl;
        else
            puts("-1");
    }
    return 0;
}
