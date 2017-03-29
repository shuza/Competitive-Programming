#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX 47000

using namespace std;

int main()
{
    long N, i;
//    freopen("in.txt", "r", stdin);
    while(cin >> N)
    {
        if(N == 0)
            break;
        cout << N << " = ";
        if(N < 0)
        {
            cout << "-1 x ";
            N *= -1;
        }
        if(N == 1)
        {
            cout << "1" << endl;
            continue;
        }
        long factor[4700], l = 0;
        while(N % 2 == 0)
        {
            factor[l++] = 2;
            N /= 2;
        }
        for(i = 3; i <= sqrt(N); i += 2)
            while(N % i == 0)
            {
                factor[l++] = i;
                N /= i;
            }
        if(N != 1)
            factor[l++] = N;
        for(i = 0; i < l; i++)
            if(i != l - 1)
                cout << factor[i] << " x ";
            else
                cout << factor[i] << endl;
    }
    return 0;
}
