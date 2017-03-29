#include <iostream>
#include <algorithm>

using namespace std;

int  divisor[1001];

bool compare(int a, int b)
{
    if(divisor[a] > divisor[b])
        return false;
    if(divisor[a] == divisor[b] && a < b)
        return false;
    return true;
}

int main()
{
    int num[1002], i;
    num[1] = 1;
    for(i = 2; i <= 1001; i++)
    {
        num[i] = i;
        divisor[i]++;
        for(int j = i + i; j <= 1000; j += i)
            divisor[j]++;
    }
    sort(num + 2, num + 1001, compare);
    int T, cas = 1;
    cin >> T;
    while(T--)
    {
        cin >> i;
        cout << "Case " << cas++ << ": " << num[i] << endl;
    }
    return 0;
}
