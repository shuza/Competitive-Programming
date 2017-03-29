#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int T, simultation[3652], N, h, i, j, P;
//    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--)
    {
        cin >> N >> P;
        memset(simultation, 0, sizeof(simultation));
        for(i = 0; i < P; i++)
        {
            cin >> h;
            j = h;
            while(j <= N)
            {
                if(j%7!=0 && j%7!=6)
                    simultation[j] = 1;
                j += h;
            }
        }
        h = 0;
        for(i = 1; i <= N; i++)
            if(simultation[i] == 1)
                h++;
        cout << h << endl;
    }
    return 0;
}
