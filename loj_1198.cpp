#include <iostream>
#include <algorithm>>

using namespace std;

int main()
{
    int T, cas = 1, i, j, n, my[50], enemy[50], ans, test;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> my[i];
        for(i = 0; i < n; i++)
            cin >> enemy[i];
        sort(my, my + n);
        sort(enemy, enemy + n);
        ans = 0;
        for(i = 0; i < n; i++)
        {
            test = -1;
            j = 0;
            while(my[i] > enemy[j] && j < n)
            {
                if(enemy[j] != -1)
                    test = j;
                j++;
            }
            if(test != -1)
            {
                my[i] = -1;
                enemy[test] = -1;
                ans += 2;
            }
        }
        for(i = 0; i < n; i++)
        {
            if(my[i] == -1)
                continue;
            j = 0;
            while(j < n && my[i] != enemy[j])
                j++;
            if(j < n)
            {
                ans++;
                my[i] = -1;
                enemy[j] = -1;
            }
        }
        cout << "Case " << cas++ <<": " << ans << endl;
    }
    return 0;
}
