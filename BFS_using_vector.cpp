#include <cstdio>
#include <vector>

using namespace std;

vector <int> G[100];

int input_g()
{
    int N, i, x, y, e;
    printf("Enter the number of nodes: ");
    scanf("%d", &N);
    printf("Enter the edge: ");
    scanf("%d", &e);
    for(i = 0; i < e; i++)
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    return N;
}

void BFS(int N, int source)
{
    vector<int> v1, v2;
    v1.push_back(source);
    int taken[100] = {0};
    printf("Level o :: %d", source);
    for(int level = 1; level < N; level++)
    {
        printf("Level %d :: ", level);
        taken[source] = 1;
        for(int i = 0; i < v1.size(); i++)
        {
            int u = v1[i];
            for(int j = 0; j < G[u].size(); j++)
            {
                int v = G[u][j];
                if(!taken[v])
                {
                    printf("%d", v);
                    taken[v] = 1;
                    v2.push_back(v);
                }
            }
        }
        if(v2.empty())
        {
            puts("EMPTY");
            break;
        }
        printf("\n");
        v1.clear();
        v1 = v2;
        v2.clear();
    }
}

int main()
{
    int N, source;
    N = input_g();
    printf( "Enter the root: ");
    scanf("%d", &source);
    BFS( N, source );
    return 0;
}
