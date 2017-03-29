#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int T, cas = 1;
//    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--)
    {
        int ax, ay, bx, by, cx, cy, dx, dy, area;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        dx = cx - (bx - ax);
        dy = cy - (by - ay);
        area = (ay-by)*dx - (ax-bx)*dy - ax*(ay-by) + ay*(ax-bx);
        area = abs(area);
        cout << "Case " << cas++ << ": " << dx << " " << dy << " " << area << endl;
    }
    return 0;
}
