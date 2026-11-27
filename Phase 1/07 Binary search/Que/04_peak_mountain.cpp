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

int peakIndexBruteForce(const vector<int> &arr) {
    const int n = arr.size();
    if (n == 0)
        return -1;

    for (int i = 0; i < n; i++) {
        bool leftOk = (i == 0) || arr[i - 1] < arr[i];
        bool rightOk = (i == n - 1) || arr[i] > arr[i + 1];

        if (leftOk && rightOk)
            return i;
    }

    return -1;
}

/* =========================================================
   Binary Search
   Time  : O(log n)
   Space : O(1)
   ========================================================= */

int peakIndexBinarySearch(const vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
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
        bool rising = arr[mid] < arr[mid + 1];
        if (rising) {
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
        else {
            right = mid;
        }
    }

    // left == right → peak index
    return left;
}

int main() {
    vector<int> arr = { 0, 2, 5, 8, 12, 9, 4 };

    cout << "Brute Force: " << peakIndexBruteForce(arr) << '\n';

    cout << "Binary Search: " << peakIndexBinarySearch(arr) << '\n';

    return 0;
}
