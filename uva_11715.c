#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=1, b ;
    double a,v, u, t, s ;
    while( scanf( "%d", &b)==1 )
    {
        if( b==0 )
            break ;
        scanf( "%lf %lf %lf", &u, &v, &t ) ;
        switch( b )
        {
            case 1:
                a=( v-u )/t ;
                s=(u*t)+(a/2)*t*t ;
                printf( "Case %d: %.3lf %.3lf\n", count++, s, a ) ;
                break ;
            case 2:
                a=t ;
                t=( v-u )/a ;
                s=u*t+(a/2)*t*t ;
                printf( "Case %d: %.3lf %.3lf\n", count++, s, t ) ;
                break ;
            case 3:
                a=v ;
                s=t ;
                v=u*u+2*a*s ;
                v=sqrt( v ) ;
                t=( v-u )/a ;
                printf( "Case %d: %.3lf %.3lf\n", count++, v, t ) ;
                break ;
            case 4:
                a=v ;
                v=u ;
                s=t ;
                u=( v*v )-( 2*a*s ) ;
                u=sqrt( u ) ;
                t=( v-u )/a ;
                printf( "Case %d: %.3lf %.3lf\n", count++, u, t ) ;
                break ;
        }
    }
    return 0;
}
