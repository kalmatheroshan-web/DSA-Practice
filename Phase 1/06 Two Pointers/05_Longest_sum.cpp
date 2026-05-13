#include <bits/stdc++.h>
using namespace std;
/*

Longest sum contiguous subArray

You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Note : A subarray is a continuous part of an array.

*/

// brute force O(N*N)
int maxSubarraySum(vector<int> &ar)
{
    int maxi = INT32_MIN;
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        int prefix = 0;
        for (int j = i; j < n; j++)
        {
            prefix += ar[j];
            if (prefix > maxi)
                maxi = prefix;
        }
    }

    return maxi;
}

// O(N) Kadane's Algorithm
int maxiSubArraySum(vector<int> &ar)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int val : ar)
    {
        sum += val;
        maxi = max(sum, maxi);

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{
    vector<int> ar = {3, 4, -5, 8, -12, 7, 6, -2};
    int answer = maxiSubArraySum(ar);
    cout << "answer is : " << answer << endl;
}