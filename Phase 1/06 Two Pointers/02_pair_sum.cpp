#include <bits/stdc++.h>
using namespace std;
/*
Given an array, arr[] and an integer target, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.

    Input: arr[] = [5, 20, 3, 2, 5, 80], x = 78
    Output: true
    Explanation: Pair (2, 80) have an absolute difference of 78.

    Input: arr[] = [90, 70, 20, 80, 50], x = 45
    Output: false
    Explanation: There is no pair with absolute difference of 45.
*/

// O(nlogn)
bool findPair(vector<int> &ar, int tar)
{
    int n = ar.size();
    if (n < 2)
        return false;
    tar = abs(tar);

    // O(nlogn)
    sort(ar.begin(), ar.end());

    // O(n)
    int s = 0, e = 1;
    while (e < n)
    {
        if (s == e)
        {
            e++;
            continue;
        }

        int diff = ar[e] - ar[s];
        if (diff == tar)
            return true;
        else if (diff > tar)
            s++;
        else
            e++;
    }
    return false;
}

bool findPair(vector<int> &ar, int tar)
{
    tar = abs(tar);
    unordered_map<int, int> freq;
    for (int x : ar)
        freq[x]++;

    for (auto &[val, cnt] : freq)
    {
        if (tar == 0 && cnt >= 2)
            return true;
        else if (tar != 0 && freq.count(val + tar))
            return true;
    }

    return false;
}
int main()
{
    vector<int> ar = {50, 20, 3, 2, 5, 80};
    int target = 45;

    cout << findPair(ar, target) << endl;
}
