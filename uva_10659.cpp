#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--)
    {
        int n, width, length, i;
        vector<int> in;
        cin >> n;
        string str;
        getline(cin, str);
        while(n--)
        {
            int test = 0;
            getline(cin, str);
            for(i = 0; i < str.size(); i++)
                if(isspace(str[i]))
                {
                    in.push_back(test);
                    test = 0;
                }
                else
                    test++;
            in.push_back(test);
            in.push_back(-1);
        }
        cin >> width >> length;
        int font = 28;
        while(font >= 8)
        {
            int x, y;
            x = 0;
            y = font;
            for(i = 0; i < in.size() - 1; i++)
            {
                int a = in[i];
                if(a == -1)
                {
                    x = 0;
                    y += font;
                    if(y > length)
                        break;
                }
                else if(x + a * font <= width)
                    x += a * font + font;
                else if(y + font <= length)
                {
                    x = 0;
                    i--;
                    y += font;
                }
                else
                {
                    y += font;
                    break;
                }
            }
            if(i == in.size()-1 && y <= length)
                break;
            font--;
        }
        if(font >= 8)
            cout << font << endl;
        else
            cout << "No solution" << endl;
    }
    return 0;
}
