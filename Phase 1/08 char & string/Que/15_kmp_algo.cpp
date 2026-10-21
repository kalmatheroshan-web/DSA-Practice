#include <bits/stdc++.h>
using namespace std;

void fill_lps(vector<int> &lps, string &text)
{
    int pre = 0, suf = 1;
    int m = text.size();

    while (suf < m)
    {
        if (text[pre] == text[suf])
        {
            lps[suf] = pre + 1;
            pre++, suf++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] == 0;
                suf++;
            }
            else
                pre = lps[pre - 1];
        }
    }
}

// time : O(N+M) space : O(M)    where M = text , N = s
int strStr(string s, string text)
{
    int n = s.size();
    int m = text.size();

    vector<int> lps(m, 0);

    // fill the lps array
    fill_lps(lps, text);

    int s_i = 0;
    int text_j = 0;

    while (s_i < n)
    {

        if (s[s_i] == text[text_j])
            s_i++, text_j++;
        else
        {
            // not matching at first
            if (text_j == 0)
                s_i++;
            else
                text_j = lps[text_j - 1];
        }

        if (text_j == m)
            return s_i - m;
    }

    return -1;
}

int main()
{
}