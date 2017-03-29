#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

#define MAXWORD 205
vector<int> g[MAXWORD];
int dis[MAXWORD];
vector<string> wordlist;

void init(){
    for(int i = 0; i < MAXWORD; i++){
        g[i].clear();
        dis[i] = -1;
    }
    wordlist.clear();
}

bool isvalid(string u, string v){
    if(u.size() != v.size())
        return false;
    int a = 0;
    for(int i = 0 ; i < u.size(); i++)
        if(u[i] != v[i])
            a++;
    if(a == 1)
        return true;
    return false;
}

void makeGraph(){
    for(int i = 0; i < wordlist.size(); i++){
        for(int j = i+1; j < wordlist.size(); j++){
            if(isvalid(wordlist[i], wordlist[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
}

int BFS(int src, int des){
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while(!q.empty()){
        src = q.front();    q.pop();
//        cout << wordlist[src] << " ";
        for(int i = 0; i < g[src].size(); i++){
            int v = g[src][i];
            if(dis[v] == -1){
                dis[v] = dis[src] + 1;
                q.push(v);
                if(v == des)
                    return dis[des];
            }
        }
    }
    return dis[des];
}

int main()
{
    READ("in.txt");
    bool line = false;
    int t;
    cin >> t;
    while(t--){
        init();
        map<string, int> mymap;
        string s;
        while(cin >> s){
            if(s == "*") break;
            mymap[s] = wordlist.size();
            wordlist.push_back(s);
//            cout << s << " " << mymap[s] << endl;
        }
//        puts("end of word");
        makeGraph();
        if(line)
            cout << endl;
        else
            line = true;
        getchar();
//        puts("query start");
        while(getline(cin, s)){
//            cout << "in: " << s << endl;
            if(s == "")
                break;
            string a, b;
            std::stringstream ss;
            ss << s;
            ss >> a >> b;
            if(mymap.find(a) == mymap.end()){
                mymap[a] = wordlist.size();
                wordlist.push_back(a);
            }
            if(mymap.find(b) == mymap.end()){
                mymap[b] = wordlist.size();
                wordlist.push_back(b);
            }
//            cout << "sjd:  " << a << " " << mymap[a] << "\t" << " " << b << " " << mymap[b] << endl;
            int src = mymap[a];
            int des = mymap[b];
            memset(dis, -1, sizeof(dis));
            cout << s << " " << BFS(src, des) << endl;
        }
    }
    return 0;
}
