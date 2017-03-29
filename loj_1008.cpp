#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int t, cas = 1;
    cin >> t;
    while(t--){
        long long N;
        cin >> N;
        long long row, col, mid;
        row =(long) sqrt(N);
        if(row*row != N)
            row++;
        col = row;
        mid = row*row - (row-1);
        if(row % 2 != 0){
            if(N > mid)
                col -= N - mid;
            else
                row -= mid - N;
        }
        else{
            if(N > mid)
                row -= N - mid;
            else
                col -= mid - N;
        }
        cout << "Case " << cas++ << ": " << col << " " << row << endl;
    }
    return 0;
}
