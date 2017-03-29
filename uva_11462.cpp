#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXAGE 101

int main()
{
    long n;
    while(cin >> n){
        if(!n)
            break;
        long age[MAXAGE] = {0};
        for(long i = 0; i < n; i++){
            int a;
            cin >> a;
            age[a]++;
        }
        bool sp = false;
        for(int i = 1; i < MAXAGE; i++){
            while(age[i]--){
                if(sp)
                    cout << " ";
                cout << i;
                sp = true;
            }
        }
        puts("");
    }
    return 0;
}
