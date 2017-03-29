#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    getchar();
    while(n--){
        string s;
        getline(cin, s);
        bool ans = true;
        stack<int> st;
        if(s.size() % 2 != 0)
            ans = false;
        else{
            for(int i = 0; i < s.size() && ans; i++)
                if(s[i] == '(' || s[i] == '[')
                    st.push(s[i]);
                else if(s[i] == ')' && !st.empty() && st.top() == '(')
                    st.pop();
                else if(s[i] == ']' && !st.empty() && st.top() == '[')
                    st.pop();
                else
                    ans = false;
        }
        if(ans && st.empty())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
