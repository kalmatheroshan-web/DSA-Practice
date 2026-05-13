#include <bits/stdc++.h>
using namespace std;

/*

    Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

    Input: nums = [0]
    Output: [[],[0]]

*/

void solve(vector<int> &ar, vector<int> &res, vector<vector<int>> &ans,
           int inx)
{
    if (inx == ar.size())
    {
        ans.push_back(res);
        return;
    }

    // take it
    res.push_back(ar[inx]);
    solve(ar, res, ans, inx + 1);

    // not take it
    res.pop_back();
    solve(ar, res, ans, inx + 1);
}

vector<vector<int>> subsets(vector<int> &ar)
{
    vector<vector<int>> ans;
    vector<int> res;

    solve(ar, res, ans, 0);

    return ans;
}

// Time O(2^n * n) space O(n * 2^n)
vector<vector<int>> subsets2(vector<int> &ar)
{
    int n = ar.size();
    int mask = 1 << n;

    vector<vector<int>> ans;

    for (int i = 0; i < mask; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(ar[j]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}
int main()
{

    cout << (1 << 5) << endl;

    return 0;
}