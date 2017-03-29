#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare( int a, int b )
{
    if( a>b )
        return true ;
    return false ;
}

long int make_num( int a[], int n )
{
    long int ans = 0 ;
    for( int i = 0 ; i<n ; i++ )
    {
        ans = ans*10 + a[i] ;
    }
    return ans ;
}

int main()
{
    long int N, num_inc, num_dic, num_test ;
    int a[11], i ;
    cin >> N ;
    while( N )
    {
        cout << "Original number was " << N << endl ;
        vector<long int> cycle ;
        bool same = false ;
        while( 1 )
        {
            for( i = 0 ; N!=0 ; i++ )
            {
                a[i] = N%10 ;
                N /= 10 ;
            }
            sort( a, a+i ) ;
            num_inc = make_num( a, i ) ;
            sort( a, a+i, compare ) ;
            num_dic = make_num( a, i ) ;
            num_test = num_dic - num_inc ;
            for( i = 0 ; i<cycle.size() ; i++ )
                if( cycle.at(i)==num_test )
                {
                    same = true ;
                    break ;
                }
            cycle.push_back( num_test ) ;
            N = num_test ;
            cout << num_dic << " - " << num_inc << " = " << num_test << endl ;
            if( same )
                break ;
        }
        cout << "Chain length " << cycle.size() << endl << endl ;
        cin >> N ;
    }
    return 0;
}
