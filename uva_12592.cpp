#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int N, i, Q;
    string first[20], second[20];
    while(cin >> N)
    {
        getchar();
        for(i = 0; i < N; i++)
        {
            getline(cin, first[i]);
            getline(cin, second[i]);
        }
        cin >> Q;
        getchar();
        while(Q--)
        {
            string query;
            getline(cin, query);
            for(i = 0; i < N; i++)
                if(first[i] == query)
                {
                    cout << second[i] << endl;
                    break;
                }
        }
    }
    return 0;
}
