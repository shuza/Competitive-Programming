#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int T, cas = 1;
    string str;
    cin >> T;
    while(T--)
    {
        stack<string> backword;
        stack<string> forwordpage;
        string current;
        cout << "Case " << cas++ << ":" << endl;
        current = "http://www.lightoj.com/";
        while(cin >> str)
        {
            if(str[0] == 'Q')
                break;
            if(str[0] == 'V')
            {
                cin >> str;
                cout << str << endl;
                backword.push(current);
                current = str;
                while(!forwordpage.empty())
                    forwordpage.pop();
            }
            else if(str[0] == 'F')
            {
                if(forwordpage.size() == 0)
                    cout << "Ignored" << endl;
                else
                {
                    backword.push(current);
                    current = forwordpage.top();
                    forwordpage.pop();
                    cout << current << endl;
                }
            }
            else if(str[0] == 'B')
            {
                if(backword.size() == 0)
                    cout << "Ignored" << endl;
                else
                {
                    forwordpage.push(current);
                    current = backword.top();
                    backword.pop();
                    cout << current << endl;
                }
            }
        }
    }
    return 0;
}
