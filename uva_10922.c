#include <stdio.h>
#include <stdlib.h>

int digitSum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    char str[1001];
    int sum, count, i;
    while(scanf("%s", str))
    {
        if(str[0] == '0')
            break;
        sum = 0;
        for(i = 0; str[i] != '\0'; i++)
            sum += str[i] - '0';
        if(sum % 9 == 0)
        {
            count = 1;
            while(sum % 9 == 0 && sum > 9)
            {
                sum = digitSum(sum);
                count++;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", str, count);
        }
        else
            printf("%s is not a multiple of 9.\n", str);
    }
    return 0;
}
