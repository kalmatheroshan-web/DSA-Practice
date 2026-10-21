#include <iostream>
#include <string>
using namespace std;

/*
Remove All Occurrences of a Substring
    - Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
      * Find the leftmost occurrence of the substring part and remove it from s.
      * Return s after removing all occurrences of part.
    - A substring is a contiguous sequence of characters in a string.
*/

// brute force
// time O(n^2) space O(1)
string removeOccurrences1(string s, string part)
{
    if (s.size() < part.size())
        return s;

    int k = part.length();
    int inx = s.find(part);

    while (inx != string::npos)
    {
        s.erase(inx, k);
        inx = s.find(part);
    }
    return s;
}

// using extra string as a stack
// time O(n*m) space O(n)
string removeOccurrences2(string s, string part)
{
    string ans;
    int m = part.size();

    for (char val : s)
    {
        ans += val;

        int k = ans.size();
        if (k >= m && ans.substr(k - m) == part)
            ans.erase(k - m, m);
    }
    return ans;
}

// in-place stack simulation (optimized)
// time O(n*m) worst case, space O(1)
string removeOccurrences3(string s, string part)
{
    int len = part.size();
    int j = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        s[j] = s[i];
        j++;

        if (j >= len && s.compare(j - len, len, part) == 0)
            j -= len;
    }
    s.resize(j);
    return s;
}

int main()
{
    string s1 = "daabcbaabcbc", part1 = "abc";
    string s2 = "axxxxyyyyb", part2 = "xy";

    cout << "Brute Force: " << removeOccurrences1(s1, part1) << endl;
    cout << "Stack (extra string): " << removeOccurrences2(s1, part1) << endl;
    cout << "In-place optimized: " << removeOccurrences3(s1, part1) << endl;

    cout << "Brute Force: " << removeOccurrences1(s2, part2) << endl;
    cout << "Stack (extra string): " << removeOccurrences2(s2, part2) << endl;
    cout << "In-place optimized: " << removeOccurrences3(s2, part2) << endl;

    return 0;
}
