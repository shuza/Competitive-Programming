#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int A,L;
    unsigned int i,count=1;
    unsigned long long int a;
    while(scanf("%ld %ld", &A, &L)!=EOF)
    {
        if(A==-1 && L==-1)
            break;
        a=A;
        for( i=1 ; a!=1 ; i++ )
        {
            if(a%2==0)
                a/=2;
            else
                a=3*a+1;
            if(a>L)
                break;
        }
        printf("Case %u: A = %ld, limit = %ld, number of terms = %u\n", count, A, L, i);
        count++;
    }
    return 0;
}
