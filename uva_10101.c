#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data ;
    char bng[10] ;
} ;

int main()
{
    long long int in ;
    int i, data[10], test, count=1 ;
    struct list ob[10] ;
    while( scanf( "%lld", &in )==1 )
    {
        if( in==0 )
        {
            printf( "%4d. 0\n", count ) ;
            count++ ;
            continue ;
        }
        for( i=0 ; in!=0 ; i++ )
        {
            if( i==1 || i==5 )
            {
                test=in%10 ;
                in/=10 ;
            }
            else
            {
                test=in%100 ;
                in/=100 ;
            }
            ob[i].data=test ;
            switch( i )
            {
                case 1:
                case 5:
                    strcpy( ob[i].bng, "shata" ) ;
                    break ;
                case 2:
                case 6:
                    strcpy( ob[i].bng, "hajar" ) ;
                    break ;
                case 3:
                case 7:
                    strcpy( ob[i].bng, "lakh" ) ;
                    break ;
                case 4:
                case 8:
                    strcpy( ob[i].bng, "kuti" ) ;
                    break ;
            }
        }
        printf( "%4d.", count ) ;
        for( i-- ; i>=0 ; i-- )
            if( ob[i].data>0 && i==0 )
                printf( " %d", ob[i].data ) ;
            else if( ob[i].data>0 )
                printf( " %d %s", ob[i].data, ob[i].bng ) ;
            else if( ob[i].data==0 && i==4 )
                printf( " %s", ob[i].bng ) ;
        printf( "\n" ) ;
        count++ ;
    }
    return 0;
}
