#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T, cas = 1, input[101], n, ans, i, test, j;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> input[i];
        ans = 0;
        for(i = 1; i <= n; i++)
            if(input[i] != i)
            {
                j = i;
                while(input[j] != i)
                    j++;
                input[j] = input[i];
                input[i] = i;
                ans++;
            }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
