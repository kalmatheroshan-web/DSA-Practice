#include <bits/stdc++.h>
using namespace std;

void lps(string &s, vector<int> &ar)
{
    int n = s.size();
    int pre = 0, suf = 1;
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

// time : O(n+m)   space : O(m)
int circular_match(string s, string txt)
{

    int n = s.size();
    int m = txt.size();

    vector<int> ar(m, 0);

    // fill the array
    lps(txt, ar);

    int i = 0;
    int j = 0;

    while (i < n + m)
    {
        if (s[i % n] == txt[j])
        {
            i++;
            j++;
            if (j == m)
                break;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = ar[j - 1];
            }
        }
    }
    if (i == n + m)
        return -1;
    return (i - m) % n;
}
int main()
{
    string s = "aaaaa";
    string txt = "aaaaa";

    cout << circular_match(s, txt) << endl;

    return 0;
}