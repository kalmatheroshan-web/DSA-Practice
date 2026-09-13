#include <iostream>
#include <vector>

using namespace std;

/*
    Brute Force
    Time  : O(n)
    Space : O(1)
*/
int searchBruteForce(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

/*
    Binary Search
    Time  : O(log n)
    Space : O(1)

    Idea:
    At every step, one half of the array is sorted.
*/
int search(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Target found
        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[left] <= arr[mid])
        {
            // Target is inside the sorted left half
            if (arr[left] <= target && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Right half is sorted
        else
        {
            // Target is inside the sorted right half
            if (arr[mid] < target && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    int target = 0;

    cout << "Brute Force : "
         << searchBruteForce(arr, target) << '\n';

    cout << "Binary Search : "
         << search(arr, target) << '\n';

    return 0;
}