#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

#define MAXNODE 3

struct node{
    bool endMark;
    int num;
    node *next[MAXNODE];
    node(){
        endMark = false;
        num = 0;
        for(int i = 0; i < MAXNODE; i++)
            next[i] = NULL;
    }
} *root;

bool addNode(string s){
    node *curr = root;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->num++;
    }
    curr->endMark = true;
}

int result(node *curr, int l){
    int ans = l * curr->num;
    for(int i = 0; i < MAXNODE; i++){
        if(curr->next[i]){
            ans = max(ans, result(curr->next[i], l+1));
        }
    }
    delete(curr);
    return ans;
}


int main()
{
    //READ();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        root = new node();
        while(n--){
            string s;
            cin >> s;
            addNode(s);
        }
        cout << result(root, 0) << endl;
    }
    return 0;
}
