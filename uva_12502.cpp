#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int A, B, C;
        cin >> A >> B >> C;
        C = C*(A + (A-B));
        int ans = C/(A+B);
        cout << ans << endl;
    }
    return 0;
}
