#include <cstdio>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

bool matrix[33][33];

void reset()
{
    for(int i = 0; i < 33; i++)
        memset( matrix[i], false, sizeof(matrix[i]) );
}

int main()
{
    int NC, cas = 1;
    while( scanf("%d", &NC) )
    {
        if(NC == 0)
            break;
        reset();
        map <int, int> index;
        int nodNum = 1;
        for(int i = 0; i < NC; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if(!index[a])
                index[a] = nodNum++;
            if(!index[b])
                index[b] = nodNum++;
            matrix[index[a]][index[b]] = matrix[index[b]][index[a]] = true;
        }
        int src, ttl;
        while( scanf("%d%d", &src, &ttl) )
        {
            if(src == 0 && ttl == 0)
                break;
            int dis[33];
            memset( dis, -1, sizeof(dis) );
            dis[index[src]] = 0;
            queue <int> q;
            q.push(index[src]);
            while( !q.empty() )
            {
                int v = q.front();
                q.pop();
                for(int i = 1; i < nodNum; i++)
                    if( matrix[v][i] && dis[i] == -1)
                    {
                        dis[i] = dis[v] + 1;
                        q.push(i);
                    }
            }
            int ans = 0;
            for(int i = 1; i < nodNum; i++)
                if( dis[i] == -1 || dis[i] > ttl )
                    ans++;
            printf( "Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cas++, ans, src, ttl );
        }
    }
    return 0;
}
