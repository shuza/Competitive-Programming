#include <iostream>

using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        int num, one;
        num = one = 1;
        while(num)
        {
            if(num < N)
            {
                num = num*10 + 1;
                one++;
            }
            num = num % N;
        }
        cout << one << endl;
    }
    return 0;
}
