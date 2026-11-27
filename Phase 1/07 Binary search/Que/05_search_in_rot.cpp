#include <iostream>
#include <vector>

using namespace std;

/*
    Brute Force
    Time  : O(n)
    Space : O(1)
*/
int searchBruteForce(const vector<int> &arr, int target) {
    // linear search
    for (int i = 0; i < arr.size(); ++i) {
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
int search(vector<int> &ar, int tar) {
    int s = 0, e = ar.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        int ele = ar[mid];
        if (ele == tar)
            return mid;

        // correct part
        bool cur_left = ar[0] <= ele;
        bool tar_left = ar[0] <= tar;

        if (cur_left == tar_left) {
            if (tar < ele)
                e = mid - 1;
            else
                s = mid + 1;
        }
        // set the tar part
        else if (cur_left)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };

    int target = 0;

    cout << "Brute Force : " << searchBruteForce(arr, target) << '\n';

    cout << "Binary Search : " << search(arr, target) << '\n';

    return 0;
}
