#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXK 102

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        map<char, int> encode;
        cin >> n;
        while(n--){
            char c;
            int tk;
            cin >> c >> tk;
            encode[c] = tk;
        }
        cin >> n;
        getchar();
        int sum = 0;
        while(n--){
            string s;
            getline(cin, s);
            for(int i = 0; i < s.size(); i++)
                if(encode.find(s[i]) != encode.end()){
                    sum += encode[s[i]];
                }
        }
        cout << (sum / 100) << ".";
        if(sum % 100 < 10)
            cout << "0";
        cout << sum % 100 << "$" << endl;
    }
    return 0;
}
