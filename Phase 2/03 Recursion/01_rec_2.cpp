#include <bits/stdc++.h>
using namespace std;

// factorail of n
int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}

// sum of n
int sum_n(int n)
{
    if (n == 1)
        return n;

    return n + sum_n(n - 1);
}

// power of 2 n
int power_2(int n)
{
    if (n == 0)
        return 1;

    return 2 * power_2(n - 1);
}

// sum of square till n
int sum_squre(int n)
{
    if (n == 1)
        return n;

    return n * n + sum_squre(n - 1);
}

// fibonacci series
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

// Palindrom
bool palindrom(string &s, int en, int st = 0)
{
    if (st >= en)
        return true;

    return (s[st] == s[en]) && palindrom(s, en - 1, st + 1);
}

// count vowel 
int cnt_vowel(string s, int i = 0)
{
    if (i == s.size())
        return 0;

    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        return 1 + cnt_vowel(s, i + 1);

    return cnt_vowel(s, i + 1);
}

// Reverse string
string reverse_str(string &s, int en, int st = 0)
{
    if (st >= en)
        return "";

    swap(s[st], s[en]);
    reverse_str(s, st + 1, en - 1);
    return s;
}

int main()
{

    cout << power_2(0) << endl;
    cout << sum_squre(4) << endl;

    return 0;
}