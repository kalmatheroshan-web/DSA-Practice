#include <bits/stdc++.h>
using namespace std;

// Brute force
int findMin(vector<int> &ar)
{
    int mini = INT32_MIN;
    int len = ar.size();

    for (int i = 0; i < len; i++)
        if (ar[i] < mini)
            mini = ar[i];

    return mini;
}

// optimize
int findMin(vector<int> &ar)
{
    int s = 0, e = ar.size() - 1;
    int mini = ar[0];

    while (s <= e)
    {
        int mid = e + (s - e) / 2;

        // Left half is sorted
        if (ar[0] <= ar[mid])
            s = mid + 1;

        // Right half is sorted
        else
        {
            mini = ar[mid];
            e = mid - 1;
        }
    }
    return mini;
}

int main()
{
    vector<int> v = {4, 5, 6, 7, -2, 1, 2};
    int mini = findMin(v);
    cout << "minimum is " << mini << endl;

    return 0;
}