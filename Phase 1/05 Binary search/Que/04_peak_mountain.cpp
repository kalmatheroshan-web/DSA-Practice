#include <iostream>
#include <vector>

using namespace std;

/*
    Problem:
    You are given an integer mountain array arr of length n.

    The values:
        - strictly increase up to a peak
        - strictly decrease after the peak

    Return the index of the peak element.

    Requirement:
        O(log n) time
*/

/* =========================================================
   Brute Force
   Time  : O(n)
   Space : O(1)
   ========================================================= */

int peakIndexBruteForce(const vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n - 1; ++i)
    {
        bool left = arr[i] > arr[i - 1];
        bool right = arr[i] > arr[i + 1];
        
        if (left && right)
            return i;
    }

    return -1;
}

/* =========================================================
   Binary Search
   Time  : O(log n)
   Space : O(1)
   ========================================================= */

int peakIndexBinarySearch(const vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        /*
            Increasing slope:

                arr[mid] < arr[mid + 1]

                Example:

                    0  2  5  8  12  9  4
                          ↑
                         mid

                Peak is to the RIGHT.
        */
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        /*
            Decreasing slope:

                arr[mid] > arr[mid + 1]

                Example:

                    0  2  5  8  12  9  4
                              ↑
                             mid

                Peak is at mid OR to the LEFT.

                Therefore we keep mid.
        */
        else
        {
            right = mid;
        }
    }

    // left == right → peak index
    return left;
}

int main()
{
    vector<int> arr = {0, 2, 5, 8, 12, 9, 4};

    cout << "Brute Force: "
         << peakIndexBruteForce(arr)
         << '\n';

    cout << "Binary Search: "
         << peakIndexBinarySearch(arr)
         << '\n';

    return 0;
}