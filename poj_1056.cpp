#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define MAXNODE 11

struct node{
    bool endMark;
    node *next[MAXNODE];
    node(){
        endMark = false;
        for(int i = 0; i < MAXNODE; i++)
            next[i] = NULL;
    }
} *root;

bool addNode(string s){
    node *cur = root;
    bool ans = false, now = false;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - '0';
        if(!ans && !now)
            ans = cur->endMark;
        if(cur->next[id] == NULL){
            cur->next[id] = new node();
            now = true;
        }
        cur = cur->next[id];
    }
    cur->endMark = true;
    return ans;
}

void delNode(node *cur){
    for(int i = 0; i < MAXNODE; i++){
        if(cur->next[i]){
            delNode(cur->next[i]);
        }
    }
    delete(cur);
}

int main()
{
    int caseno = 1;
    string s;
    while(cin >> s){
        bool isPrefix = false;
        root = new node();
        isPrefix = addNode(s);
        while(cin >> s){
            if(s[0] == '9') break;
            isPrefix = addNode(s);
        }
        if(!isPrefix)
            cout << "Set " << caseno++ << " is immediately decodable" << endl;
        else
            cout << "Set " << caseno++ << " is not immediately decodable" << endl;
        delNode(root);
    }
    return 0;
}
