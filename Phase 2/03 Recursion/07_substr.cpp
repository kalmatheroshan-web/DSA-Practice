#include <bits/stdc++.h>
using namespace std;

/*
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
void solve(const string &s, vector<string> &ans,
           string &current, int index)
{
    if (index == static_cast<int>(s.size()))
    {
        ans.push_back(current);
        return;
    }

    // Exclude current character
    solve(s, ans, current, index + 1);

    // Include current character
    current.push_back(s[index]);
    solve(s, ans, current, index + 1);
    current.pop_back();
}

vector<string> powerSet(string s)
{
    vector<string> ans;
    string current;

    solve(s, ans, current, 0);
    return ans;
}

int main()
{
    string s = "abc";
    vector<string> ans = powerSet(s);

    for (auto val : ans)
        cout << val << endl;

    return 0;
}
