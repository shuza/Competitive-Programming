#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
#define MAXITEM 100000

int main()
{
    READ();
    int t;
    bool line = false;
    cin >> t;
    getchar();
    while(t--){
        if(line)
            puts("");
        line = true;
        string s;
        getline(cin, s);
        getline(cin, s);
        istringstream is(s);
        int n = 1;
        int position[MAXITEM];
        int a;
        while(is >> a)
            position[n++] = a;
        string arr[MAXITEM];
        for(int i = 1; i < n; i++){
            string d;
            cin >> d;
            a = position[i];
            arr[a] = d;
        }
        getchar();
        for(int i = 1; i < n; i++)
            cout << arr[i] << endl;
    }
    return 0;
}
