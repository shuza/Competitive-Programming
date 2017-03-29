#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#define MAXSQ 10001000

using namespace std;

int main()
{
    long long N;
//    freopen("in.txt", "r", stdin);
    while(cin >> N)
    {
        if(!N)
            break;
        long long ans = 0, num = abs(N);
        int divisor = 0;
        N = num;
        for(long long i = 2; i*i <= num; i++)
        {
            while(N % i == 0)
            {
                N /= i;
                if(ans != i)
                    divisor++;
                ans = i;
            }
        }
        if(N != 1 && N != num)
        {
            divisor++;
            ans = N;
        }
        if(divisor < 2)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
