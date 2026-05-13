#include <bits/stdc++.h>
using namespace std;
/*
    Try brute forct of O(N*N)
*/

bool canSplit(vector<int> &ar)
{
    int n = ar.size();
    int total = 0;

    // sum
    for (int val : ar)
        total += val;

    int prefix = 0;

    for (int i = 0; i < n - 1; i++)
    {
        prefix += ar[i];
        if (prefix == total - prefix)
            return 1;
    }

    return 0;
}

int main()
{
    vector<int> ar = {3, 4, -2, 5, 8, 20, -10, 8};
    bool divide_subarray = canSplit(ar);
    cout << "is it Possible to divide " << divide_subarray << endl;
}