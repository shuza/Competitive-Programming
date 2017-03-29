#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, i, T, side[3];
    cin >> T;
    while(T--)
    {
        cin >> side[0] >> side[1] >> side[2];
        sort(side, side + 3);
        if(side[0] + side[1] > side[2])
            cout << "OK" << endl;
        else
            cout << "Wrong!!" << endl;
    }
    return 0;
}
