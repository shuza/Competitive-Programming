#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define G 34943

int main()
{
    READ();
    string s;
    while(getline(cin, s)){
        if(s[0] == '#')
            break;
        if(s.size() == 0){
            puts("00 00");
            continue;
        }
        unsigned long sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum = ((sum << 8) + s[i]) % G;
        }
        sum <<= 16;
        sum = G - (sum % G);
        printf("%02X %02X\n", sum >> 8, sum % 256);
    }
    return 0;
}
