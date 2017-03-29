#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <cctype>
#define INF (1<<30)
#define eps 1e-11
#define REP(i, n) for(__typeof(n) i = 0; i < (n); i++)

#define maxnode 1005
#define fillA 0
#define fillB 1
#define emptyA 2
#define emptyB 3
#define pourAB 4
#define pourBA 5

using namespace std;

struct state {int a, b; };
state parent[maxnode][maxnode];
int work[maxnode][maxnode];
int dis[maxnode][maxnode];
string s[] = {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A"};

void display(int ax, int bx)
{
    if(dis[ax][bx] == 0)
        return;
    display(parent[ax][bx].a, parent[ax][bx].b);
    int x = work[ax][bx];
    cout << s[x] << endl;
}

int main()
{
    state ux, u, v;
    int N, x;
    while(cin >> ux.a >> ux.b >> N)
    {
        REP(i, maxnode) REP(j, maxnode) dis[i][j] = INF;
        u.a = u.b = dis[0][0] = 0;
        queue<state> q;
        q.push(u);
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            if(u.b == N)
                break;
            x = dis[u.a][u.b] + 1;

            //  fill A
            v.a = ux.a;
            v.b = u.b;
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = fillA;
                q.push(v);
            }

            //  fill B
            v.a = u.a;
            v.b = ux.b;
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = fillB;
                q.push(v);
            }

            //  empty A
            v.a = 0;
            v.b = u.b;
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = emptyA;
                q.push(v);
            }

            //  empty B
            v.a = u.a;
            v.b = 0;
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = emptyB;
                q.push(v);
            }

            //  pour A -> B
            if(u.a + u.b < ux.b)
            {
                v.b = u.a + u.b;
                v.a = 0;
            }
            else
            {
                v.b = ux.b;
                v.a = u.a - (ux.b - u.b);
            }
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = pourAB;
                q.push(v);
            }

            // pour B -> A
            if(u.a + u.b < ux.a)
            {
                v.a = u.a + u.b;
                v.b = 0;
            }
            else
            {
                v.a = ux.a;
                v.b = u.b - (ux.a - u.a);
            }
            if(dis[v.a][v.b] > x)
            {
                parent[v.a][v.b] = u;
                dis[v.a][v.b] = x;
                work[v.a][v.b] = pourBA;
                q.push(v);
            }
        }
        display(u.a, u.b);
        cout << "success" << endl;
    }
    return 0;
}
