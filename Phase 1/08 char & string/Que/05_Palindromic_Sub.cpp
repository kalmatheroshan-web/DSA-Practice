#include <iostream>
using namespace std;

bool palin(string s, int st, int e)
{
    while (st < e)
    {
        if (s[st] != s[e])
            return 0;
        st++;
        e--;
    }

    return 1;
}

// time : O(N*N*N) space : O(1)
int countSubstrings(string s)
{

    int n = s.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (palin(s, i, j))
                cnt++;
        }
    }

    return cnt;
}

// time : O(N*N) space : O(1)
int countSubstrings(string s)
{
    int center = 0, cnt = 0, n = s.size();

    // odd
    while (center < n)
    {
        int k = center, j = center;
        while (k >= 0 && j < n)
        {
            if (s[k] == s[j])
                k--, j++, cnt++;
            else
                break;
        }
        center++;
    }

    center = 0;

    // even
    while (center < n - 1)
    {
        int k = center, j = center + 1;
        while (k >= 0 && j < n)
        {
            if (s[k] == s[j])
                cnt++, k--, j++;
            else
                break;
        }
        center++;
    }
    return cnt;
}

int main()
{
}