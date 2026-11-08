#include <bits/stdc++.h>
using namespace std;
/*

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

    Input: nums1 = [1,2,2,2], nums2 = [2,2]
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

// Time O(n*m)      space O(min(n,m))
vector<int> intersection1(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    // O(n*m)
    for (int val_a : a)
    {
        for (int val_b : b)
        {
            if (val_a == val_b)
            {
                if (find(ans.begin(), ans.end(), val_a) == ans.end())
                {
                    ans.push_back(val_a);
                }
                break;
            }
        }
    }

    return ans;
}

// time O(nlogn + mlogm + m + n)     space O(min(n,m))
vector<int> intersection2(vector<int> &ar1, vector<int> &ar2)
{
    vector<int> ans;

    sort(ar1.begin(), ar1.end()); // nlogn
    sort(ar2.begin(), ar2.end()); // mlogm

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

// time O(l1 + l2)  space O(min(n,m))
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

/*
Same as about but faster in thinking
    Time: O(n + m)
    Space: O(n)
*/
vector<int> intersection(vector<int> &a, vector<int> &b)
{
    unordered_set<int> st(a.begin(), a.end());
    vector<int> ans;

    for (int x : b)
    {
        if (st.erase(x))
        {
            ans.push_back(x);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
