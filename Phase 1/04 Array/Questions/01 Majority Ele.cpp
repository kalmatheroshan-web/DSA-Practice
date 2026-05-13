#include <bits/stdc++.h>
using namespace std;

// time O(N*N) space O(1)
int majorityElement(vector<int> &ar)
{

    int n = ar.size(), ans = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (ar[j] == ar[i])
                cnt++;
        }
        if (cnt > n / 2)
            return ar[i];
    }

    return ans;
}

// time O(N*logn) space O(N)
int majorityElement2(vector<int> &ar)
{
    int n = ar.size();
    map<int, int> mp; // ele cnt

    // O(N*logn)
    for (int val : ar)
    {
        mp[val]++;
    }

    // O(N)
    for (auto val : mp)
    {
        int cur = val.second;
        if (cur > n / 2)
            return val.first;
    }
    return -1;
}

/*
    Boyer–Moore Voting Algorithm
*/
int majorityElement3(vector<int> &ar)
{
    int n = ar.size();
    int count = 0, ele = 0;

    // Moore voting
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = ar[i];
            count = 1;
        }
        else if (ar[i] == ele)
        {
            count++;
        }
        else
            count--;
    }

    count = 0;

    // check wheather it is correct or not
    for (int val : ar)
    {
        if (ele == val)
            count++;
    }

    if (count > n / 2)
        return ele;
    return -1;
}

int main()
{

    vector<int> ar = {1, 4, 2, 4, 4, 3, 8};
    int major = majorityElement3(ar);

    cout << "Majority Element is " << major << endl;

    return 0;
}