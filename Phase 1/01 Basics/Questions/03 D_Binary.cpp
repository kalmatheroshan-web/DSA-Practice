#include <bits/stdc++.h>
using namespace std;

using namespace std;

string decimal_binary_string(int num)
{
    string ans = "";
    while (num > 0)
    {
        ans += (num % 2 == 0 ? '0' : '1');
        num >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 18;
    string value = decimal_binary_string(n);
    cout << "value " << value << endl;
    return 0;
}