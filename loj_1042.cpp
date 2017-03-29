#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, cas = 1;
    cin >> t;
    while(t--){
        long N;
        cin >> N;
        int bit[32] = {0};
        int l = 0;
        while(N){
            bit[l++] = N % 2;
            N /= 2;
        }
        int i = 0, one = 0;
        while(!bit[i])
            i++;
        while(bit[i]){
            i++;
            one++;
        }
        bit[i] = 1;
        bit[i-1] = 0;
        one--;
        if(i == l)
            l++;
        if(one > 0){
            for(int j = 0; j < one; j++)
                bit[j] = 1;
            while(one < i)
                bit[one++] = 0;
        }
        long mul = 1, ans = 0;
        for(i = 0; i < l; i++){
            ans += bit[i]*mul;
            mul *= 2;
        }
        cout << "Case " << cas++ << ": " << ans << endl;
    }
    return 0;
}
