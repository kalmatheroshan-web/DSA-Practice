#include <iostream>
#include <vector>

using namespace std;

/*
Question: Find the Missing Number in an Array

Problem Statement:

You are given an array arr of size (N-1) containing distinct integers from 1 to N. Exactly one number is missing from the sequence.

Write a function to find the missing number.

Example 1
Input:
arr = [1, 2, 4, 5]

Output:
3
Example 2
Input:
arr = [2, 3, 1, 5]

Output:
4
Constraints
1 <= N <= 10^5
All elements are distinct.
Every element is in the range [1, N].
Exactly one number is missing.
*/

int missingNum(vector<int> &arr)
{
    int n = arr.size() + 1;
    int xorr = 0;

    int len = n - 1;

    // O(N)
    for (int i = 0; i < len; i++)
        xorr ^= arr[i] ^ i + 1;

    return xorr ^ n;
}

int missing_num1(vector<int> &arr)
{
    int n = arr.size() + 1;
    int sum = (1LL * n * (n + 1)) / 2;

    --n;

    // O(N)
    for (int i = 0; i < n; i++)
        sum -= arr[i];

    return sum;
}

int main()
{

    return 0;
}