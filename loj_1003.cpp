#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
#define MAXNODE 10005

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, cas = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> mymap;
        int l = 0;
        int arr[MAXNODE] = {0};
        int visit[MAXNODE] = {0};
        vector<int> g[MAXNODE];
        while(n--){
            string a, b;
            cin >> a >> b;
            if(mymap.find(a) == mymap.end()){
                mymap[a] = l++;
            }
            if(mymap.find(b) == mymap.end()){
                mymap[b] = l++;
            }
            int u = mymap[a];
            int v = mymap[b];
            g[u].push_back(v);
            arr[v]++;
        }
        bool ans = true;
        for(int i = 0; i < l; i++){
            int j = 0;
            while(j < l && (arr[j] || visit[j]))
                j++;
            if(j < l && !arr[j] && !visit[j]){
                visit[j] = 1;
                for(int k = 0; k < g[j].size(); k++){
                    int x = g[j][k];
                    arr[x]--;
                }
            }
            else{
                ans = false;
                break;
            }
        }
        cout << "Case " << cas++ << ": ";
        if(ans)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
