#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    int n;
    while(cin >> n){
        if(!n)
            break;
        priority_queue<long long, vector<long long>, greater<long long> > q;
        while(n--){
            long a;
            cin >> a;
            q.push(a);
        }
        long long cost = 0;
        do{
            long long a = q.top();  q.pop();
            a += q.top();   q.pop();
            cost += a;
            q.push(a);
        }while(q.size() > 1);
        cout << cost << endl;
    }
    return 0;
}
