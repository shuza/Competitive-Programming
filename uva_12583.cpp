#include <cstdio>

using namespace std;

int main()
{
    int cas = 1, T, n, k, i, j;
    char name[501];
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(cas <= T)
    {
        scanf("%d%d%s", &n, &k, name);
        int ans = 0;
        for(i = 1; i < n; i++)
        {
            for(j = 1; j <= k && i - j >= 0; j++)
                if(name[i] == name[i - j])
                {
                    ans++;
                    break;
                }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}
