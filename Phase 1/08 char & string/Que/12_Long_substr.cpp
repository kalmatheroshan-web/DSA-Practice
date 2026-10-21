#include <iostream>
using namespace std;
/*
Given a string s, find the length of the longest substring without duplicate characters.
*/

// time : O(N*N*N), space : O(1)
int lengthOfLongestSubstring(string s)
{
    int n = s.size();

    int max_len = 0;
    for (int row = 0; row < n; row++)
    {
        for (int inside = row; inside < n; inside++)
        {
            int len = 0;
            int seen[128] = {};

            for (int sub_str = row; sub_str <= inside; sub_str++)
            {
                char cur = s[sub_str];
                seen[cur]++;
                if (seen[cur] > 1)
                {
                    len = 0;
                    break;
                }
                len++;
            }
            max_len = max(len, max_len);
        }
    }

    return max_len;
}

// time O(N*N)
int lengthOfLongestSubstring2(string s)
{
    int n = s.size();
    int mx_l = 0;

    for (int i = 0; i < n; i++)
    {
        int len = 0;
        int ar[128] = {};

        for (int j = i; j < n; j++)
        {
            char cur = s[j];

            if (ar[cur])
                break;

            ar[cur]++;
            len++;
            mx_l = max(mx_l, len);
        }
    }
    return mx_l;
}

// time O(N) sliding window
int lengthOfLongestSubstring3(string s)
{
    int n = s.size();
    int mx_l = 0, len = 0;

    int ar[128] = {};

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        char cur = s[i];

        if (ar[cur])
        {
            while (j < i)
            {
                len--;
                ar[s[j]]--;
                if (s[j++] == s[i])
                    break;
            }
        }

        ar[cur]++;
        len++;
        mx_l = max(mx_l, len);
    }
    return mx_l;
}

int main()
{
    string s = "ABABC";
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
