#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int T, cas = 1, n, m, num;
    string str;
    cin >> T;
    while(T--)
    {
        deque<int> Q;
        cout << "Case " << cas++ << ":" << endl;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> str;
            if(str[1] == 'u' && str[4] == 'L')
            {
                cin  >> num;
                if(Q.size() == n)
                {
                    cout << "The queue is full" << endl;
                    continue;
                }
                cout << "Pushed in left: " << num << endl;
                Q.push_front(num);
            }
            else if(str[1] == 'u' && str[4] == 'R')
            {
                cin  >> num;
                if(Q.size() == n)
                {
                    cout << "The queue is full" << endl;
                    continue;
                }
                cout << "Pushed in right: " << num << endl;
                Q.push_back(num);
            }
            else if(str[1] == 'o' && str[3] == 'L')
            {
                if(Q.empty())
                {
                    cout << "The queue is empty" << endl;
                    continue;
                }
                cout << "Popped from left: " << Q.front() << endl;
                Q.pop_front();
            }
            else if(str[1] == 'o' && str[3] == 'R')
            {
                if(Q.empty())
                {
                    cout << "The queue is empty" << endl;
                    continue;
                }
                cout << "Popped from right: " << Q.at(Q.size() - 1) << endl;
                Q.pop_back();
            }
        }
    }
    return 0;
}
