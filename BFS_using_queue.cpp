#include <cstdio>
#include <queue>
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

void BFS(int N, int src)
{
    queue<int> Q;
    Q.push(src);
    int taken[100] = {0}, dis[100] = {0};
    taken[src] = 1;
    while(!Q.empty())
    {
        int u = Q.front();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if(!taken[v])
            {
                taken[v] = 1;
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    printf("Root = %d\n", src);
    for(int i = 1; i <= N; i++)
        printf("%d node distance from root = %d\n", i, dis[i]);
}

int main()
{
    int N, src;
    N = input_g();
    printf("Enter the root: ");
    scanf("%d", &src);
    BFS(N, src);
    return 0;
}
