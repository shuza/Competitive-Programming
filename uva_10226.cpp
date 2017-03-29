	//	algo: try

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

long totalTree;

struct node{
    bool endMark;
    int num;
    node *next[130];
    node(){
        endMark = false;
        num = 0;
        for(int i = 0; i < 130; i++)
            next[i] = NULL;
    }
} *root;

int getId(char c){
    return (int) c;
}

char getCh(int n){
    return (char) n;
}

void del(node *curr, string s){
    if(curr->endMark){
        cout << s;
        double d = (double) curr->num / totalTree * 100;
        printf(" %.4lf\n", d);
    }
    for(int i = 0; i < 130; i++)
        if(curr->next[i]){
            char c = getCh(i);
            del(curr->next[i], s+c);
        }
    delete(curr);
}

void addNode(char *str, int l){
    node *curr = root;
    for(int i = 0; i < l; i++){
        int id = getId(str[i]);
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endMark = true;
    curr->num++;
}

int main()
{
    bool line = false;
    int t;
    scanf("%d", &t);
    getchar();
    char s[33];
    gets(s);
    while(t--){
        if(line)
            puts("");
        line = true;
        totalTree = 0;
        root = new node();
        while(gets(s)){
            if(strlen(s) == 0) break;
            totalTree++;
            addNode(s, strlen(s));
        }
        del(root, "");
    }
    return 0;
}
