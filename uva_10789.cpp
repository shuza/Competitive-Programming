#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

bool isPrime(int a)
{
    if(a == 2)
        return true;
    if(a < 2 || a % 2 == 0)
        return false;
    int sq = sqrt(a);
    for(int i = 3; i <= sq; i += 2)
        if(a % i == 0)
            return false;
    return true;
}

int main()
{
    int N, cas = 1;
    cin >> N;
    while(N--)
    {
        string s;
        cin >> s;
        int frequency[125] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            int c = (int) s[i];
            frequency[c]++;
        }
        vector<int> ans;
        for(int i = 48; i < 125; i++)
            if(isPrime(frequency[i]))
                ans.push_back(i);
        cout << "Case " << cas++ << ": ";
        if(!ans.size())
        {
            cout << "empty" << endl;
            continue;
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            cout << (char) ans[i];
        cout << endl;
    }
    return 0;
}
