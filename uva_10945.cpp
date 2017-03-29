#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

int main()
{
    READ("in.txt");
    string s;
    while(getline(cin, s)){
        if(s == "DONE")
            break;
        string in = "";
        for(int i = 0; i < s.size(); i++)
            if(isalpha(s[i])){
                in += tolower(s[i]);
            }
        bool palindrom = true;
        for(int i = 0; i < in.size()/2; i++)
            if(in[i] != in[in.size()-i-1]){
                palindrom = false;
                break;
            }
        if(palindrom)
            puts("You won't be eaten!");
        else
            puts("Uh oh..");
    }
    return 0;
}
