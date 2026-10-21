#include <bits/stdc++.h>
using namespace std;

int give_num(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int romanToDecimal(string &s)
{
    int n = s.size();
    int ans = 0;

    ans = give_num(s[0]);

    for (int i = 1; i < n; i++)
    {
        int a = give_num(s[i - 1]);
        int cur = give_num(s[i]);

        if (cur > a)
            ans += cur - a * 2;

        else
            ans += cur;
    }

    return ans;
}
int main()
{
}