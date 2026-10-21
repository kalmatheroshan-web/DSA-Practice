#include <bits/stdc++.h>
using namespace std;

// time : O(2^n) space : O(n)
void subset_sum(vector<int> &ar, int sum, int inx)
{
    if (inx == ar.size())
    {
        cout << sum << " ";
        return;
    }

    // take it
    subset_sum(ar, sum + ar[inx], inx + 1);

    // not take it
    subset_sum(ar, sum, inx + 1);
}

void solve(vector<vector<int>> &ans, vector<int> &ar, vector<int> &res, int inx)
{
    if (inx == ar.size())
    {
        ans.push_back(res);
        return;
    }

    // take it
    res.push_back(ar[inx]);
    solve(ans, ar, res, inx + 1);

    res.pop_back();
    // not take it
    solve(ans, ar, res, inx + 1);
}

vector<vector<int>> subset_sum2(vector<int> &ar)
{
    vector<vector<int>> ans;
    vector<int> res;
    solve(ans, ar, res, 0);
    return ans;
}

int main()
{
    vector<int> ar = {3, 4, 5};
    // subset_sum(ar, 0, 0);

    vector<vector<int>> ans = subset_sum2(ar);

    for (auto val : ans)
    {
        int sum = 0;
        for (auto ele : val)
            sum += ele;
        cout << sum << " - ";
        for (auto ele : val)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}