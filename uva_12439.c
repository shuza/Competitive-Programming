#include <stdio.h>
#include <stdlib.h>

int fun( char c[] )
{
    int l ;
    l=strlen( c ) ;
    if( l==8 )
    {
        if( c[0]=='F' )
            return 2 ;
        if( c[0]=='N' )
            return 11 ;
        return 12 ;
    }
    if( l==7 )
    {
        if( c[0]=='J' )
            return 1 ;
        return 10 ;
    }
    if( l==6 )
        return 8 ;
    if( l==5 )
    {
        if( c[0]=='M' )
            return 3 ;
        return 4 ;
    }
    if( l==4 )
    {
        if( c[3]=='e' )
            return 6 ;
        return 7 ;
    }
    if( l==3 )
        return 5 ;
    return 9 ;
}

int main()
{
    char month[11], month1[11] ;
    long int year, year1, y, y1, ans ;
    int date, date1, T, m, m1, count=1 ;
    scanf( "%d", &T ) ;
    while( count<=T )
    {
        scanf( "%s %d, %ld", month, &date, &year ) ;
        scanf( "%s %d, %ld", month1, &date1, &year1 ) ;
        m=fun( month ) ;
        m1=fun( month1 ) ;
        y=year/4-year/100+year/400 ;
        y1=year1/4-year1/100+year1/400 ;
        ans=y1-y ;
        if( m<=2 && ( year%400==0 || ( year%4==0 && year%100!=0 ) ) )
                ans++ ;
        if( year1%400==0 || ( year1%4==0 && year1%100!=0 ) )
        {
            if( m1==1 )
                ans-- ;
            else if( m1==2 && date1<29 )
                ans-- ;
        }
        printf( "Case %d: %ld\n", count, ans ) ;
        count++ ;
    }
    return 0;
}
