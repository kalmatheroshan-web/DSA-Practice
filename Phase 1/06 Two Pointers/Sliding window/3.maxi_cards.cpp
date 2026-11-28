#include <bits/stdc++.h>
using namespace std;

// Max points from k cards taken from either end.
// Time: O(k), Space: O(1)
long long mx_point(const vector<int> &ar, int k) {
    const int n = ar.size();
    k = min(k, n); // guard against k > n
    if (k <= 0)
        return 0;

    // Start by taking all k cards from the left
    long long cur = accumulate(ar.begin(), ar.begin() + k, 0LL);
    long long best = cur;

    // Move one card at a time from the left side to the right side
    for (int i = 1; i <= k; i++) {
        cur += ar[n - i] - ar[k - i];
        best = max(best, cur);
    }

    return best;
}

int main() {

    vector<int> ar = { 6, 2, 3, 4, 7, 2, 1, 7, 1 };
    int k = 4;

    cout << "Ans : " << mx_point(ar, k) << '\n';
    return 0;
}
