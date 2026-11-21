#include <bits/stdc++.h>
using namespace std;

// Find the missint element in the AP series

// Binary search approach — O(log n)
int findMissing(vector<int> &ar) {
    int n = ar.size();

    // Find the actual common difference from the smaller gap
    int first = ar[1] - ar.front();
    int last = ar.back() - ar[n - 2];

    long long d = abs(first) < abs(last) ? first : last;
    int a = ar.front();

    // If the last element is correct, the missing number is after it
    int s = 1, e = n;
    if (ar.back() == a + (e - 1) * d)
        return ar.back() + d;

    // Find the first index where the expected AP value is missing
    while (s < e) {
        int mid = s + (e - s) / 2;

        if (ar[mid] == a + mid * d)
            s = mid + 1;
        else
            e = mid;
    }

    return a + s * d;
}

// Linear search approach — O(n)
int findMissing1(vector<int> &ar) {
    int n = ar.size();

    // Get the common difference
    int d = ar[1] - ar[0];

    // Find the first gap that is not equal to the common difference
    for (int i = 2; i < n; i++) {
        int gap = ar[i] - ar[i - 1];

        if (gap != d)
            return ar[i] - d;
    }

    // Missing element is after the last element
    return ar.back() + d;
}

int main() { return 0; }
