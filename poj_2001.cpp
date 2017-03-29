#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXNODE 27

struct node{
    bool endMark, prefix;
    node *next[MAXNODE];
    node(){
        endMark = false;
        prefix = true;
        for(int i = 0; i < MAXNODE; i++)
            next[i] = NULL;
    }
} *root;

void addNode(string s){
    node *cur = root;
    bool now = false;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!now)
            cur->prefix = false;
        if(cur->next[id] == NULL){
            cur->next[id] = new node();
            now = true;
        }
        cur = cur->next[id];
        if(!now)
            cur->prefix = false;
    }
    cur->endMark = true;
}

int srcNode(string s){
    node *cur = root;
    for(int i = 0; i < s.size(); i++){
    //    cout << s[i] << " " << cur->prefix << endl;
        if(cur->prefix){
  //          cout << "i: " << i << endl;
//            puts("return..");
            return i;
        }
        int id = s[i] - 'a';
        cur = cur->next[id];
    }
    return s.size();
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
    vector<string> v;
    string s;
    root = new node();
    while(cin >> s){
        v.push_back(s);
        addNode(s);
    }
    for(int i = 0; i < v.size(); i++){
        int j = srcNode(v[i]);
        cout << v[i] << " " << v[i].substr(0, j) << endl;
    }
    delNode(root);
    return 0;
}
