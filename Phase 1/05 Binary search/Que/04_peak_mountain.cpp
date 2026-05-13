#include <iostream>
using namespace std;

/*

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.


Example 1:

    Input: arr = [0,1,0]
    Output: 1

Example 2:

    Input: arr = [0,2,1,0]
    Output: 1

Example 3:

    Input: arr = [0,10,5,2]
    Output: 1
*/

// brute force
int peakIndexInMountainArray(int ar[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (ar[i] > ar[i + 1])
            return i;
    }
    return -1;
}

// binary search
int peakIndexInMountainArray(int ar[], int len)
{
    int st = 0, end = len - 1;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid + 1 < len && ar[mid] > ar[mid + 1])
        {
            ans = mid;
            end = mid - 1;
        }
        else
            st = mid + 1;
    }
    return ans;
}

int main()
{

    return 0;
}