#include <bits/stdc++.h>
using namespace std;
// time O(N*N)
int lps(string &s)
{
    int n = s.size();
    int len = 0;

    for (int i = 0; i < n - 1; i++)
    {
        string front = "";
        for (int j = 0; j <= i; j++)
            front += s[j];

        string back = "";
        for (int j = n - 1 - i; j < n; j++)
            back += s[j];

        if (front == back)
            len = len > back.size() ? len : back.size();
    }
    return len;
}
// time : O(N) space : O(N)
int lps2(string &s)
{
    int n = s.size();
    int pre = 0, suf = 1;

    vector<int> ar(n, 0);

    // now fill the array
    while (suf < n)
    {
        if (s[pre] == s[suf])
        {
            ar[suf] = pre + 1;
            pre++, suf++;
        }
        else
        {
            if (pre == 0)
            {
                ar[suf] = 0;
                suf++;
            }
            else
                pre = ar[pre - 1];
        }
    }

    return ar[n - 1];
}
int main()
{

    string a = "ABCDEABCD";
    int ans = lps(a);
    cout << "Answer is " << ans << endl;

    return 0;
}
