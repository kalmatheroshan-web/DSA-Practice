#include <iostream>
#include <algorithm>
using namespace std;
/*
    time : O(max(an,bn))
    space : O(max(an,bn))
*/
string add_str(string &a, string &b)
{
    int an = a.size();
    int bn = b.size();
    int cr = 0, i = an - 1;

    string ans;

    int diff = an - bn;

    // add from reverse
    while (i >= diff)
    {
        int sum = (a[i] - '0') + (b[i - diff] - '0') + cr;
        ans += sum % 10 + '0';
        cr = sum / 10;
        i--;
    }

    // add remaining part of a
    while (i >= 0)
    {
        int sum = (a[i] - '0') + cr;
        ans += sum % 10 + '0';
        cr = sum / 10;
        i--;
    }

    // add remaining carry
    if(cr > 0)
    {
        ans += cr;
    }

    // reverse ans
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s1 = "26583";
    string s2 = "698";
    int a = s1.size(), b = s2.size();

    string ans;

    if (a >= b)
        ans = add_str(s1, s2);
    else
        ans = add_str(s2, s1);
    cout << "answer is " << ans << endl;
}
