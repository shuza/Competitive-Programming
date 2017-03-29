        /**********     uva  10820      ***********/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXSIVE 50000

int phi[MAXSIVE+2];
int sum[MAXSIVE+2];

void sive(){
    int flag[MAXSIVE+2] = {0};
    for(int i = 1; i <= MAXSIVE; i++)
        phi[i] = i;
    flag[1] = 1;
    phi[1] = 0;
    for(int i = 2; i <= MAXSIVE; i++)
        if(!flag[i]){
            phi[i] = i - 1;;
            for(int j = i+i; j <= MAXSIVE; j += i){
                flag[j] = 1;
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    for(int i = 1; i <= MAXSIVE; i++)
        sum[i] = sum[i-1] + phi[i];
}

int main()
{
    int n;
    sive();
    while(cin >> n){
        if(!n)
            break;
        cout << (2*sum[n]+1) << endl;
    }
    return 0;
}
