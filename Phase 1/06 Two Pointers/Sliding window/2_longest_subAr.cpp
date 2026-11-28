#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// NOTE: All approaches assume array elements are non-negative.
// Problem: find the length of the longest subarray with sum <= k.

// 1) Brute force
// Time: O(N^2), Space: O(1)
int longestSubarrayBrute(const vector<int> &arr, int k) {
    int n = arr.size();
    int maxLen = 0;

    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int end = start; end < n; end++) {
            sum += arr[end];

            if (sum > k)
                break; // adding more non-negative numbers can't help

            maxLen = max(maxLen, end - start + 1);
        }
    }
    return maxLen;
}

// 2) Better: sliding window (shrink until valid)
// Time: O(N+N) (each element is added once and removed at most once), Space: O(1)
int longestSubarrayBetter(const vector<int> &arr, int k) {
    int n = arr.size();
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right]; // expand

        while (sum > k && left <= right) // shrink
        {
            sum -= arr[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

// 3) Optimized: sliding window that never shrinks
// The window size only stays the same or grows. When it becomes invalid,
// we slide it one step (remove one from the left) instead of shrinking it.
// The window length at the end is the answer.
// Time: O(N), Space: O(1)
int longestSubarrayOptimized(const vector<int> &arr, int k) {
    int n = arr.size();
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right]; // expand

        if (sum > k) // invalid: slide the window by one
        {
            sum -= arr[left];
            left++;
        }

        if (sum <= k)
            maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<int> arr = { 2, 5, 1, 7, 10 };
    int k = 14;

    cout << "Brute Force : " << longestSubarrayBrute(arr, k) << endl;
    cout << "Better      : " << longestSubarrayBetter(arr, k) << endl;
    cout << "Optimized   : " << longestSubarrayOptimized(arr, k) << endl;
    return 0;
}
