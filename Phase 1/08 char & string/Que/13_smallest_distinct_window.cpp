#include <iostream>
using namespace std;
/*
    Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.
*/

// time : O(N*N*N) space: O(1)
int findSubString(string &s)
{
    bool ar[26] = {};
    int n = s.size(), len = 0;

    int ans = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        int inx = s[i] - 'a';
        if (ar[inx] == 0)
            len++;

        ar[inx] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            bool check[26] = {};
            int mn_l = 0;
            for (int k = i; k <= j; k++)
            {
                int inx = s[k] - 'a';

                if (check[inx] == 0)
                    mn_l++;

                check[inx] = 1;
            }

            if (mn_l == len && j - i + 1 >= len)
                ans = min(ans, j - i + 1);
        }
    }

    return ans;
}

// time : O(N*N) space: O(1)
int findSubString2(string &s)
{
    bool ar[26] = {};
    int n = s.size(), len = 0;

    int ans = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        int inx = s[i] - 'a';
        if (ar[inx] == 0)
            len++;

        ar[inx] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        bool check[26] = {};
        int ln = 0, wd_l = 0;

        for (int j = i; j < n; j++)
        {

            int inx = s[j] - 'a';

            wd_l++;
            if (check[inx] == 0)
                ln++;

            if (ln == len)
                break;

            check[inx] = 1;
        }

        if (len == ln)
            ans = min(ans, wd_l);
    }

    return ans;
}

// time : O(N) space: O(1) -> sliding window
int findSubString3(string &s)
{
    bool ar[26] = {};
    int n = s.size(), len = 0;

    int ans = INT32_MAX;

    // Step 1: Count total distinct characters in the string
    for (int i = 0; i < n; i++)
    {
        int inx = s[i] - 'a';
        if (ar[inx] == 0)
            len++;
        ar[inx] = 1;
    }

    int j = 0;
    int check[26] = {}; // frequency array for current window
    int ln = 0;         // count of distinct chars in current window

    // Step 2: Sliding window
    for (int i = 0; i < n; i++)
    {
        int inx = s[i] - 'a';
        if (check[inx] == 0)
            ln++;
        check[inx]++;

        // Step 3: If window has all distinct characters
        while (ln == len)
        {
            ans = min(ans, i - j + 1); // update answer

            // shrink from left
            int leftInx = s[j] - 'a';
            check[leftInx]--;
            if (check[leftInx] == 0)
                ln--;
            j++;
        }
    }

    return ans;
}

int main()
{
}