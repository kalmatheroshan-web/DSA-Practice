#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
Given an array of positive integers arr sorted in a strictly increasing order,
and an integer k, find the k-th positive integer that is missing from this array.
*/

// ============================================================
// Brute Force Approach
// Time Complexity: O(N + answer)
// Space Complexity: O(1)
// ============================================================

int linearSearchApproach(const vector<int> &arr, int k)
{
    int current = 1;
    int i = 0;
    int missingCount = 0;

    while (true)
    {
        // Current number exists in the array
        if (i < arr.size() && arr[i] == current)
        {
            i++;
        }
        else
        {
            // Current number is missing
            missingCount++;

            if (missingCount == k)
            {
                return current;
            }
        }

        current++;
    }
}

// ============================================================
// Hash Set Approach
// Time Complexity: O(N + answer) average
// Space Complexity: O(N)
// ============================================================

int hashSetApproach(const vector<int> &arr, int k)
{
    unordered_set<int> s(arr.begin(), arr.end());

    int missingCount = 0;
    int current = 1;

    while (true)
    {
        if (s.find(current) == s.end())
        {
            missingCount++;

            if (missingCount == k)
            {
                return current;
            }
        }

        current++;
    }
}

/*
============================================================
IMPORTANT OBSERVATION FOR BINARY SEARCH
============================================================

If the array contained no missing numbers:

    {1, 2, 3, 4, 5}

Then:

    arr[i] = i + 1

Therefore:

    arr[i] - 1 = i


For example:

    index:      0   1   2   3    4    5
    array:     {2,  3,  4,  7,  11,  12}

Let's calculate how many numbers are missing before/at arr[i].

Missing numbers before arr[i]:

    missing_count = arr[i] - (i + 1)


For the above array:

    index:          0   1   2   3   4   5
    arr[i]:         2   3   4   7  11  12

    missing_count:  1   1   1   3   6   6


Example:

    arr[4] = 11

    missing_count = 11 - (4 + 1)
                  = 11 - 5
                  = 6

The six missing positive numbers before 11 are:

    1, 5, 6, 8, 9, 10


============================================================
WHY ARE WE LOOKING FOR index >= k?
============================================================

Suppose k = 5.

At index 4:

    arr[4] = 11

    missing_count = 6

So the 5th missing number occurs before 11.

We want the FIRST index where:

    missing_count >= k

Therefore, we perform a binary search for the first index
whose missing_count is >= k.


============================================================
WHY IS THE ANSWER index + k?
============================================================

Suppose the first index satisfying:

    missing_count >= k

is 'index'.

Let:

    missing_count = arr[index] - (index + 1)

There are:

    missing_count

missing numbers before arr[index].

The k-th missing number is therefore:

    arr[index] - (missing_count - k + 1)


Substitute:

    missing_count = arr[index] - (index + 1)


So:

    kth_missing
        = arr[index] - {arr[index] - (index + 1) - k + 1}

        = arr[index] - {arr[index] - index - 1 - k + 1}

        = arr[index] - {arr[index] - index - k}

        = index + k


Therefore:

    ANSWER = index + k


============================================================
*/

// ============================================================
// Binary Search Approach
// Time Complexity: O(log N)
// Space Complexity: O(1)
// ============================================================

int binarySearchApproach(const vector<int> &arr, int k)
{
    int left = 0;
    int right = arr.size() - 1;

    // If the k-th missing number is after the entire array,
    // ans will remain arr.size().
    int ans = arr.size();

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Number of missing positive integers before arr[mid]
        int missingCount = arr[mid] - (mid + 1);

        if (missingCount >= k)
        {
            // This index could contain the answer.
            // Try to find an earlier index.
            ans = mid;
            right = mid - 1;
        }
        else
        {
            // Not enough missing numbers yet.
            // Move to the right.
            left = mid + 1;
        }
    }

    // If ans is the first index where missingCount >= k:
    // answer = ans + k
    return ans + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11, 12};

    int k = 5;

    // Brute Force
    cout << "Linear Search Answer : "
         << linearSearchApproach(arr, k)
         << endl;

    // Hash Set
    cout << "Hash Set Answer      : "
         << hashSetApproach(arr, k)
         << endl;

    // Binary Search
    cout << "Binary Search Answer : "
         << binarySearchApproach(arr, k)
         << endl;

    return 0;
}