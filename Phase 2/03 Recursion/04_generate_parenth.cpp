#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans, string &temp, int n, int l, int r)
{
    if (l == n && r == n)
    {
        ans.push_back(temp);
        return;
    }

    if (l > n || l < r)
        return;

    // left
    temp.push_back('(');
    solve(ans, temp, n, l + 1, r);
    temp.pop_back();

    // right
    temp.push_back(')');
    solve(ans, temp, n, l, r + 1);
    temp.pop_back();
}

vector<string> generat_parenthes(int n)
{
    vector<string> ans;
    string temp;
    solve(ans, temp, n, 0, 0);
    return ans;
}

int main()
{
    int n = 2;
    vector<string> ans = generat_parenthes(n);

    for (auto val : ans)
        cout << val << " ";

    return 0;
}