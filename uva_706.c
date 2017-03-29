#include <stdio.h>
#include <stdlib.h>

void upRow(int a, int n)
{
    if(a == 1 || a == 4)
    {
        printf(" ");
        while(n--)
            printf(" ");
        printf(" ");
        return;
    }
    printf(" ");
    while(n--)
        printf("-");
    printf(" ");
    return;
}

void betUpMid(int a, int n)
{
    if(a == 1 || a == 2 || a == 3 || a == 7)
    {
        printf(" ");
        while(n--)
            printf(" ");
        printf("|");
        return;
    }
    if(a == 5 || a == 6)
    {
        printf("|");
        while(n--)
            printf(" ");
        printf(" ");
        return;
    }
    printf("|");
    while(n--)
        printf(" ");
    printf("|");
    return;
}

int main()
{
    int digit[9], s, n, i, digitNo;
    while(scanf("%d %d", &s, &n) == 2)
    {
        if(s == 0 && n == 0)
            break;
        digitNo = 0;
        if(n == 0)
        {
            digit[0] = 0;
            digitNo++;
        }
        while(n)
        {
            digit[digitNo++] = n % 10;
            n /= 10;
        }
        for(i = digitNo - 1; i >= 0; i--)
        {
            upRow(digit[i], s);
            if(i != 0)
                printf(" ");
        }
        printf("\n");
        for(n = 0; n < s; n++)
        {
            for(i = digitNo - 1; i >= 0; i--)
            {
                betUpMid(digit[i], s);
                if(i != 0)
                    printf(" ");
            }
            printf("\n");
        }
        for(i = digitNo - 1; i >= 0; i--)
        {
            if(digit[i] == 7 || digit[i] == 0)
                upRow(1, s);
            else if(digit[i] == 4)
                upRow(2, s);
            else
                upRow(digit[i], s);
            if(i != 0)
                printf(" ");
        }
        printf("\n");
        for(n = 0; n < s; n++)
        {
            for(i = digitNo - 1; i >= 0; i--)
            {
                if(digit[i] == 2)
                    betUpMid(5, s);
                else if(digit[i] == 4 || digit[i] == 5 || digit[i] == 9)
                    betUpMid(2, s);
                else if(digit[i] == 6)
                    betUpMid(0, s);
                else
                    betUpMid(digit[i], s);
                if(i != 0)
                    printf(" ");
            }
            printf("\n");
        }
        for(i = digitNo - 1; i >= 0; i--)
        {
            if(digit[i] == 7)
                upRow(1, s);
            else
                upRow(digit[i], s);
            if(i != 0)
                printf(" ");
        }
        printf("\n\n");
    }
    return 0;
}
