#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char a[1001], b[1001], c[1001];
    int i, j, visit[1001];
    while(gets(a))
    {
        gets(b);
        memset(visit, 0, sizeof(visit));
        int count = 0;
        for(i = 0; a[i] != NULL; i++)
        {
            for(j = 0; b[j] != NULL; j++)
                if(a[i] == b[j] && visit[j] == 0)
                {
                    c[count++] = a[i];
                    visit[j] = 1;
                    break;
                }
        }
        for(i = 0; i < count; i++)
            for(j = 1; j < count; j++)
                if(c[j - 1] > c[j])
                {
                    char x = c[j - 1];
                    c[j - 1] = c[j];
                    c[j] = x;
                }
        for(i = 0; i < count; i++)
            printf("%c", c[i]);
        printf("\n");
    }
    return 0;
}
