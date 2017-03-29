#include <iostream>

using namespace std;

int main()
{
    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int primeNo = 25;
    int T, cas = 1, n, i, primefact;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << "Case " << cas++ << ": " << n << " = ";
        primefact = 0;
        int ans[25] = {0};
        while(n > 1)
        {
            int num = n;
            for(i = 0; num != 1; i++)
            {
                while(num % prime[i] == 0)
                {
                    ans[i]++;
                    num /= prime[i];
                }
            }
            if(i > primefact)
                primefact = i;
            n--;
        }
        for(i = 0; i < primefact; i++)
        {
            if(i != 0)
                cout << " * ";
            cout << prime[i] << " (" << ans[i] << ")";
        }
        cout << endl;
    }
    return 0;
}
