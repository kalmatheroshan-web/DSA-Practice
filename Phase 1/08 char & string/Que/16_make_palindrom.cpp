#include <bits/stdc++.h>
using namespace std;

/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.
*/
bool isPalin(string &s, int st, int e)
{
    while (st < e)
    {
        if (s[st] == s[e])
            st++, e--;
        else
            return false;
    }
    return true;
}

// time : O(N*N) space O(1)
string shortestPalindrome(string s)
{

    int n = s.size();

    // single character or space
    if (n <= 1)
        return s;

    int long_palin = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // find longest palindrom
        if (isPalin(s, 0, i))
        {
            long_palin = i;
            break;
        }
    }

    string remains = s.substr(long_palin + 1);
    reverse(remains.begin(), remains.end());

    return remains + s;
}

void lps(string &s, vector<int> &ar)
{
    int pre = 0, suf = 1;
    int n = s.size();

    while (suf < n)
    {
        if (s[pre] == s[suf])
        {
            ar[suf] = ++pre;
            suf++;
        }
        else
        {
            if (pre == 0)
                ar[suf++] = 0;
            else
                pre = ar[pre - 1];
        }
    }
}

// time : O(N)  space : O(N)
string shortestPalindrome(string s)
{

    int n = s.size();
    if (n <= 1)
        return s;

    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + "#" + rev;

    vector<int> ar(combined.size(), 0);

    // fill the array
    lps(combined, ar);

    int lps_val = ar.back();
    string ans = rev.substr(0, n - lps_val);

    return ans + s;
}

int main()
{
    
}