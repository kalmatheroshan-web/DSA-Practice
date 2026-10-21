#include <bits/stdc++.h>
using namespace std;

/*          masking
You are given a string. You need to return the power-set (in any order) of the string.
Note: The string s contains lowercase letter of alphabet.

Examples:
Input: s = a
Output: ["","a"]
Explanation: empty string and "a" are only sets.

Input: s = abc
Output: ["", "a", "ab", "abc", "ac", "b", "bc", "c"]
Explanation: empty string, a, ab, abc, ac, b, bc, c are the sets.
*/

void solve(string s, vector<string> &ans)
{
    int n = s.size();
    if (n == 0)
    {
        return;
    }

    // Total number of subsets is 2^n
    int power_2n = 1 << n;

    // Iterate through all possible subsets using bitmask
    for (int mask = 0; mask < power_2n; mask++)
    {
        string cur = "";

        // Check each bit of the mask to build the current subset
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                cur += s[i];
        }
        ans.push_back(cur);
    }
}

vector<string> powerSet(string s)
{
    vector<string> ans;
    solve(s, ans);

    return ans;
}

int main()
{
    string s = "abc";
    vector<string> ans = powerSet(s);

    // Print all generated subsets
    for (auto val : ans)
        cout << val << endl;

    return 0;
}
