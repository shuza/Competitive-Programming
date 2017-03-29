#include <iostream>

using namespace std;

int main()
{
    int T, cas = 1;
    cin >> T;
    while(T--)
    {
        int n, p, q, i, w, ans = 0, sum = 0;
        cin >> n >> p >> q;
        for(i = 0; i < n; i++)
        {
            cin >> w;
            if(i < p && sum + w <= q)
            {
                ans++;
                sum += w;
            }
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
