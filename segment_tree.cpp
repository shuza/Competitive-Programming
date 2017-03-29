        /*********        LightOJ  1082       ***********/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#define MX 100005

using namespace std;

int arr[MX], tree[3*MX];

void makeTree(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e) / 2;
    makeTree(left, b, mid);
    makeTree(right, mid+1, e);
    if(tree[left] < tree[right])
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
    return;
}

int querry(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return MX;
    if(b >= i && e <= j)
        return tree[node];
    int l = node * 2;
    int r = node * 2 + 1;
    int mid = (b+e) / 2;
    int p1 = querry(l, b, mid, i, j);
    int p2 = querry(r, mid+1, e, i, j);
    if(p1 < p2)
        return p1;
    return p2;
}

int main()
{
    int cas = 1, T;
//    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--)
    {
        int N, Q;
        scanf("%d%d", &N, &Q);
        for(int i = 1; i <= N; i++)
            scanf("%d", &arr[i]);
        makeTree(1, 1, N);
        printf("Case %d:\n", cas++);
        while(Q--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n", querry(1, 1, N, i, j));
        }
    }
    return 0;
}
