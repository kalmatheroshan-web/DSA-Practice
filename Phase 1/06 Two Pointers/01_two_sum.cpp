#include <bits/stdc++.h>
using namespace std;

/*
    Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target.

    Input: arr[] = [0, -1, 2, -3, 1], target = -2
    Output: true
    Explanation: arr[3] + arr[4] = -3 + 1 = -2

    Input: arr[] = [1, -2, 1, 0, 5], target = 0
    Output: false
    Explanation: None of the pair makes a sum of 0

    Input: arr[] = [11], target = 11
    Output: false
    Explanation: No pair is possible as only one is present in arr[]

*/

// O(N*N)
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

// O(N*logN)
vector<int> twoSum(vector<int> &ar, int tar)
{
    vector<pair<int, int>> vp;
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        vp.push_back({ar[i], i});
    }

    sort(vp.begin(), vp.end());
    int s = 0, e = n - 1;

    while (s < e)
    {
        int sum = vp[s].first + vp[e].first;

        if (tar == sum)
            return {vp[s].second, vp[e].second};

        if (sum > tar)
            e--;
        else
            s++;
    }

    return {};
}

// O(N)
vector<int> two_n_Sum(vector<int> &ar, int tar)
{
    unordered_map<int, int> inx;
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        int other = tar - ar[i];
        if (inx.find(other) != inx.end())
        {
            return {i, inx[other]};
        }
        inx[ar[i]] = i;
    }

    return {};
}

int main()
{

    vector<int> ar = {2, 7, 11, 15};
    int target = 9;

    vector<int> pair = twoSum(ar, target);
    cout << "two possible " << ar[pair[0]] << " " << ar[pair[1]] << endl;
}