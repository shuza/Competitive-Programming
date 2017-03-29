#include <iostream>

using namespace std;

int invmod(int a, int p){
    int ans, pow = p - 3;
    ans = a % p;
    while(pow > 0){
        ans = (ans * (a % p)) % p;
    }
    return ans;
}

int main()
{
    int a, p;
    cin >> a >> p;
    int ans = invmod(a, p);
    cout << ans;
    return 0;
}
