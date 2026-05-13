#include <iostream>
#include <vector>
using namespace std;
/*
409. Longest Palindrome
    Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

    Letters are case sensitive, for example, "Aa" is not considered a palindrome.

    Input: s = "abccccdd"
    Output: 7

    Input: s = "ab"
    Output: 1

    even
        even even

    odd
        even odd even

*/

int longestPalindrome(string s)
{
    vector<int> low(26, 0);
    vector<int> upp(26, 0);

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if ('a' <= s[i])
            low[s[i] - 'a']++;
        else
            upp[s[i] - 'A']++;
    }

    int cnt = 0;

    // lower
    for (int i = 0; i < 26; i++)
    {
        if (low[i] % 2 != 0)
            cnt += low[i] - 1;
        else
            cnt += low[i];
    }

    // upper
    for (int i = 0; i < 26; i++)
    {
        if (upp[i] % 2 != 0)
            cnt += upp[i] - 1;
        else
            cnt += upp[i];
    }

    // odd checking
    for (int i = 0; i < 26; i++)
    {
        if (low[i] % 2)
            return cnt + 1;
        if (upp[i] % 2)
            return cnt + 1;
    }

    return cnt;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = longestPalindrome(s);
    cout << "The length of the longest palindrome is: " << result << endl;

    return 0;
}