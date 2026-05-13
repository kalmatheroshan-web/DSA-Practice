#include <iostream>
using namespace std;

/*
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.

    Input: s = "abca"
    Output: true

    Input: s = "aba"
    Output: true

    Input: s = "deeee"
    Output: true
 
    Input: s = "cbbcc" 
    Output: true
*/

bool isvalid(string &s, int st, int e)
{
    while (st <= e)
    {
        if (s[st] != s[e])
            return false;
        st++;
        e--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int st = 0, e = s.size() - 1;

    while (st <= e)
    {
        if (s[st] != s[e])
        {
            return isvalid(s, st + 1, e) || isvalid(s, st, e - 1);
        }
        st++;
        e--;
    }
    return true;
}

int main()
{
}