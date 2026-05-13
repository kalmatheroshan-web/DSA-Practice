#include <bits/stdc++.h>
using namespace std;

void lps(string &s, vector<int> &ar)
{
    int pre = 0, suf = 1;
    while (suf < s.size())
    {
        if (s[suf] == s[pre])
        {
            ar[suf] = ++pre;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                ar[suf] = 0;
                suf++;
            }
            else
            {
                pre = ar[pre - 1];
            }
        }
    }
}
// time : O(M+N) space : O(M)
int repeatedStringMatch(string a, string b)
{
    int n = a.size(), m = b.size();
    vector<int> ar(m, 0);

    // Fill LPS array for b
    lps(b, ar);

    int fr = 0, sc = 0;
    int max_len = n * ((m + n - 1) / n + 2); // max characters to scan

    while (fr < max_len)
    {
        if (a[fr % n] == b[sc])
        {
            fr++;
            sc++;
            if (sc == m)
                return (fr + n - 1) / n;
        }
        else
        {
            if (sc == 0)
                fr++;
            else
                sc = ar[sc - 1];
        }
    }

    return -1;
}

int main()
{

    return 0;
}