#include <bits/stdc++.h>
using namespace std;
/*

Given two integer arrays nums1 and nums2, return ar1 array of their intersection. Each element in the result must be unique and you may return the result in any order.

    Input: nums1 = [1,2,2,ar2], nums2 = [2,2]
    Output: [2]

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]

    ar1 => 1 2 2 2 3 4
    ar2 => 2 2 3 3
    ans => 2 3

    ar1 => 1 2 3
    ar2 => 3 4
    ans => 3

*/


vector<int> intersection1(vector<int> &ar1, vector<int> &ar2)
{
    vector<int> ans;
    int n = ar1.size();
    int m = ar2.size();
    // O(n*m)
    for (int i = 0; i < n; i++)
    {
        int current = ar1[i];
        for (int j = 0; j < m; j++)
        {
            if (current == ar2[j])
            {
                if (find(ans.begin(), ans.end(), current) == ans.end())
                {
                    ans.push_back(current);
                }
                break;
            }
        }
    }

    return ans;
}

// time O(nlogn + mlogm + m + n) space O(min(n,m))
vector<int> intersection2(vector<int> &ar1, vector<int> &ar2)
{
    vector<int> ans;

    sort(ar1.begin(), ar1.end());
    sort(ar2.begin(), ar2.end());

    int n = ar1.size(), m = ar2.size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (ar1[i] == ar2[j])
        {
            if (ans.empty() || ans.back() != ar2[j])
                ans.push_back(ar2[j]);

            i++, j++;
        }
        else if (ar1[i] > ar2[j])
            j++;

        else
            i++;
    }

    return ans;
}

// time O(l1 + l2) space O(1)
vector<int> intersection3(vector<int> &nums1, vector<int> &nums2)
{
    int occur[1001] = {};
    int l1 = nums1.size();
    int l2 = nums2.size();
    vector<int> ans;

    // O(l1)
    for (int i = 0; i < l1; i++)
    {
        if (occur[nums1[i]] == 0)
        {
            occur[nums1[i]]++;
        }
    }

    // O(l2)
    for (int i = 0; i < l2; i++)
    {
        if (occur[nums2[i]] == 1)
        {
            occur[nums2[i]] = 0;
            ans.push_back(nums2[i]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}