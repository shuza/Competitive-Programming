#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d1, d2, m1, m2, y1, y2, y, T, count=1 ;
    scanf( "%d", &T ) ;
    while( T>=count )
    {
        scanf( "%d/%d/%d %d/%d/%d", &d1, &m1, &y1, &d2, &m2, &y2 ) ;
        if( y1<y2 || ( y1==y2 && m1<m2 ) || ( y1==y2 && m1==m2 && d1<d2 ) )
        {
            printf( "Case #%d: Invalid birth date\n", count ) ;
            count++ ;
            continue ;
        }
        if( d1<d2 )
            m2++ ;
        if( m1<m2 )
            y2++ ;
        y=y1-y2 ;
        if( y>130 )
            printf( "Case #%d: Check birth date\n", count ) ;
        else
            printf( "Case #%d: %d\n", count, y ) ;
        count++ ;
    }
    return 0;
}
