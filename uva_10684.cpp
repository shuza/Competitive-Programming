#include <iostream>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    while( n )
    {
        int max = 0, pre = 0, test ;
        while( n )
        {
            cin >> test ;
            if( test+pre>0 )
                pre += test ;
            else
                pre = 0 ;
            if( pre>max )
                max = pre ;
            n-- ;
        }
        if( max )
            cout << "The maximum winning streak is " << max << "." << endl ;
        else
            cout << "Losing streak." << endl ;
        cin >> n ;
    }
    return 0;
}
