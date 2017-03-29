#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

string s="abcdefghijklmnopqrstuvwxyz";
vector<string>v2, v3, v4, v5;
long sum, sum2, sum3, sum4, sum5;

void alpha2(){
    sum2 = sum;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j < s.size(); j++){
            string str = "";
            str += s[i];
            str += s[j];
            v2.push_back(str);
            sum2++;
        }
}

void alpha3(){
    sum3 = sum2;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j < s.size(); j++)
            for(int k = j + 1; k < s.size(); k++){
                string str = "";
                str += s[i];
                str += s[j];
                str += s[k];
                v3.push_back(str);
                sum3++;
            }
}

void alpha4(){
    sum4 = sum3;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j < s.size(); j++)
            for(int k = j + 1; k < s.size(); k++)
                for(int l = k + 1; l < s.size(); l++){
                    string str = "";
                    str += s[i];
                    str += s[j];
                    str += s[k];
                    str += s[l];
                    v4.push_back(str);
                    sum4++;
                }
}

void alpha5(){
    sum5 = sum4;
    for(int i = 0; i < s.size(); i++)
        for(int j = i + 1; j < s.size(); j++)
            for(int k = j + 1; k < s.size(); k++)
                for(int l = k + 1; l < s.size(); l++)
                    for(int m = l + 1; m < s.size(); m++){
                        string str = "";
                        str += s[i];
                        str += s[j];
                        str += s[k];
                        str += s[l];
                        str += s[m];
                        v5.push_back(str);
                        sum5++;
                    }
}

bool isValid(string s){
    if(s.size() == 1)
        return true;
    for(int i = 1; i < s.size(); i++)
        if(s[i-1] >= s[i])
            return false;
    return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    sum = 26;
    alpha2();
    alpha3();
    alpha4();
    alpha5();
    string s;
    while(cin >> s){
        if(!isValid(s)){
            puts("0");
            continue;
        }
        int l = s.size();
        long ans = 0;
        switch(l){
        case 1:
            ans = s[0] - 'a' + 1;
            break;
        case 2:
            for(int i = 0; i < v2.size(); i++)
                if(v2[i] == s){
                    ans = i + 1;
                    break;
                }
            ans += sum;
            break;
        case 3:
            for(int i = 0; i < v3.size(); i++)
                if(v3[i] == s){
                    ans = i + 1;
                    break;
                }
            ans += sum2;
            break;
        case 4:
            for(int i = 0; i < v4.size(); i++)
                if(v4[i] == s){
                    ans = i + 1;
                    break;
                }
            ans += sum3;
            break;
        case 5:
            for(int i = 0; i < v5.size(); i++)
                if(v5[i] == s){
                    ans = i + 1;
                    break;
                }
            ans += sum4;
            break;
        }
        cout << ans << endl;
    }
    return 0;
}
