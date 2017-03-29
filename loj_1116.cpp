#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, cas = 1;
    long long N, i;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << "Case " << cas++ << ": ";
        if(N % 2 != 0)
            cout << "Impossible" << endl;
        else
        {
            i = 2;
            while(N%i != 0 || (N/i) % 2 == 0)
                i += 2;
            cout << N/i << " " << i << endl;
        }
    }
    return 0;
}
