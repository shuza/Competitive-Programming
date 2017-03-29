	// algo: try

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)

struct node{
    bool endMark;
    node *next[13];
    node(){
        endMark = false;
        for(int i = 0; i < 13; i++)
            next[i] = NULL;
    }
} *root;

bool addNode(string str, int l){
    node *curr = root;
    for(int i = 0; i < l; i++){
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        else if(i == l-1)
            return false;
        curr = curr->next[id];

        // this is prefix of new node
        if(curr->endMark)
            return false;
    }
    curr->endMark = true;
    return true;
}

void del(node *curr){
    for(int i = 0; i < 13; i++)
        if(curr->next[i]){
            del(curr->next[i]);
        }
    delete(curr);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        bool result = true;
        root = new node();
        int n;
        cin >> n;

        while(n--){
            string s;
            cin >> s;
            if(result){
                result = addNode(s, s.size());
            }
        }
        del(root);
        if(result)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
