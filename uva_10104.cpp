#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclidean(int a, int b){
    if(b == 0)
        return pii(1, 0);
    pii d = extendedEuclidean(b, a % b);
    return pii(d.y, d.x - d.y * (a/b));
}

int main()
{
    int a, b;
    while(cin >> a >> b){
        pii d = extendedEuclidean(a, b);
        int r = (a*d.x) + (b*d.y);
        cout << d.x << " " << d.y << " " << r << endl;
    }
    return 0;
}
