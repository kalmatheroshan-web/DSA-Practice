#include <iostream>
#include <string>
using namespace std;
/*
Remove the dublicates

    - You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

    - We repeatedly make duplicate removals on s until we no longer can.

    - Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

    Input: s = "abbaca"
    Output: "ca"

    Input: s = "azxxzy"
    Output: "ay"
*/

// time : O(n*n), space : O(1)
string removeDuplicates(string s)
{
    if (s.size() == 1)
        return s;

    int i = 0;

    while (!s.empty() && i < s.length() - 1)
    {

        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = 0;
        }
        else
            i++;
    }
    return s;
}

// time : O(n), space : O(n)
string removeDuplicates2(string s)
{
    string ans;

    for (char val : s)
    {
        if (ans.empty() || ans.back() != val)
            ans += val;
        else
            ans.pop_back();
    }

    return ans;
}

// imagenary stack
// time : O(n), space : O(1)
string removeDuplicates3(string s)
{
    int k = 0;
    for (char val : s)
    {
        if (k > 0 && val == s[k - 1])
        {
            k--;
        }
        else
        {
            s[k] = val;
            k++;
        }
    }
    return s.substr(0, k);
}

int main()
{
    string s1 = "abbaca";
    string s2 = "azxxzy";

    cout << "Input: " << s1 << endl;
    cout << "removeDuplicates  (O(n^2)): " << removeDuplicates(s1) << endl;
    cout << "removeDuplicates2 (O(n))  : " << removeDuplicates2(s1) << endl;
    cout << "removeDuplicates3 (O(1))  : " << removeDuplicates3(s1) << endl;

    cout << "\nInput: " << s2 << endl;
    cout << "removeDuplicates  (O(n^2)): " << removeDuplicates(s2) << endl;
    cout << "removeDuplicates2 (O(n))  : " << removeDuplicates2(s2) << endl;
    cout << "removeDuplicates3 (O(1))  : " << removeDuplicates3(s2) << endl;
}
