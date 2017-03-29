#include <iostream>
#include <cstdio>

using namespace std;

int binarytodec(char str[])
{
    int ans = 0, i = 0, mul = 128;
    while(str[i] != '\0')
    {
        ans += (str[i] - '0') * mul;
        mul /= 2;
        i++;
    }
    return ans;
}

int strtodec(char str[])
{
    int ans = 0, i = 0;
    while(str[i] != '\0')
    {
        ans = ans*10 + (str[i] - '0');
        i++;
    }
    return ans;
}

int main()
{
    int T, cas = 1;
//    freopen("in.txt", "r", stdin);
    cin >> T;
    while(T--)
    {
        char first[16], second[28], str[10];
        int num1[4], num2[4], i, j, index = 0;
        cin >> first;
        for(i = 0, j = 0; first[i] != '\0'; i++)
            if(first[i] == '.')
            {
                str[j] = '\0';
                num1[index++] = strtodec(str);
                j = 0;
            }
            else
                str[j++] = first[i];
        str[j] = '\0';
        num1[index++] = strtodec(str);
        cin >> second;
        for(i = 0, j = 0, index = 0; second[i] != '\0'; i++)
            if(second[i] == '.')
            {
                str[j] = '\0';
                num2[index++] = binarytodec(str);
                j = 0;
            }
            else
                str[j++] = second[i];
        str[j] = '\0';
        num2[index++] = binarytodec(str);
        bool mass = true;
        for(i = 0; i < 4; i++)
            if(num1[i] != num2[i])
            {
                mass = false;
                break;
            }
        if(mass)
            cout << "Case " << cas++ << ": Yes" << endl;
        else
            cout << "Case " << cas++ << ": No" << endl;
    }
    return 0;
}
