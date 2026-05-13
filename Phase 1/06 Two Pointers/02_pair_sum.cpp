#include <bits/stdc++.h>
using namespace std;
/*
Given an array, arr[] and an integer target, return true if there exists a pair of elements in the array whose absolute difference is x, otherwise, return false.
*/

// O(nlogn)
bool findPair(vector<int> &ar, int tar)
{

    int n = ar.size();
    if (tar < 0)
        tar = abs(tar);

    // Sort the array - O(n log n)
    sort(ar.begin(), ar.end());

    int s = 0, e = 1;

    // O(n)
    while (e < n)
    {
        while (s == e)
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

    return 0;
}

int main()
{
    vector<int> ar = {50, 20, 3, 2, 5, 80};
    int target = 45;

    cout << findPair(ar, target) << endl;
}