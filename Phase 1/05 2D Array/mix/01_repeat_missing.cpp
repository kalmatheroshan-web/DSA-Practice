
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &ar) {
    int rep = 0, mis = 0;
    int n = ar.size();

    // Mark visited elements
    for (auto &row : ar) {
        for (int val : row) {
            int inx = abs(val) - 1;

            int r = inx / n;
            int c = inx % n;

            if (ar[r][c] < 0)
                rep = inx + 1;
            else
                ar[r][c] = -ar[r][c];
        }
    }

    // Find missing element
    for (int inx = 0; inx < n * n; inx++) {
        int r = inx / n;
        int c = inx % n;

        if (ar[r][c] > 0) {
            mis = inx + 1;
            break;
        }
    }

    return { rep, mis };
}

int main() {
    vector<vector<int>> ar = {
        { 4, 3, 6 },
        { 2, 1, 1 },
        { 7, 8, 9 }
    };

    vector<int> ans = findMissingAndRepeatedValues(ar);

    cout << "Repeating number: " << ans[0] << endl;
    cout << "Missing number: " << ans[1] << endl;

    return 0;
}
