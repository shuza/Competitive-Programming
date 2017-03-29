#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#define MAXINT 2147483647
#define LL long long int

using namespace std;

LL strToDec(char str[])
{
    LL num = 0;
    int len, i = 0;
    len = strlen(str);
    while(str[i] == '0')
        i++;
    if(len-i > 10)
        return -1;
    for(i = 0; i < len; i++)
        num = num * 10 + (str[i]-'0');
    if(num > MAXINT)
        return -1;
    return num;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char first[1000], second[1000], op, str[3005];
    int i, j;
    while(gets(str))
    {
        puts(str);
        i = 0;
        while(str[i] == ' ')
            i++;
        for(; str[i] >= '0' && str[i] <= '9'; i++)
            first[i] = str[i];
        first[i] = '\0';
        while(str[i] != '*' && str[i] != '+')
            i++;
        op = str[i++];
        while(!(str[i] >= '0' && str[i] <= '9'))
            i++;
        for(j = 0; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++, j++)
            second[j] = str[i];
        second[j] = '\0';
        LL num1 = strToDec(first);
        if(num1 == -1)
            cout << "first number too big" << endl;
        LL num2 = strToDec(second);
        if(num2 == -1)
            cout << "second number too big" << endl;
        if(num1 != -1 && num2 != -1)
        {
            if(op == '+')
                num1 += num2;
            else
                num1 *= num2;
            if(num1 > MAXINT)
                cout << "result too big" << endl;
        }
        else if(!(op == '*' && (num1 == 0 || num2 == 0)))
            cout << "result too big" << endl;
    }
    return 0;
}
